#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
using ll = long long;
 
int compress(vector<int> &v) {
    vector<int> vals(all(v));
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    for (int &x : v) x = int(lower_bound(all(vals), x) - begin(vals));
    return sz(vals);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int cantX = compress(x), cantY = compress(y);
    vector<int> freqX(cantX, 0), freqY(cantY, 0);
    for (int i = 0; i < n; i++) {
        freqX[x[i]]++, freqY[y[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (freqX[x[i]] - 1LL) * (freqY[y[i]] - 1LL);
    }
    cout << ans << '\n';
    
    return 0;
}