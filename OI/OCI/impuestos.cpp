#include <bits/stdc++.h>
 
using namespace std;

#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

using ll = long long;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<ll> e(n), a(n);
    for (ll &x : e) cin >> x;
    for (ll &x : a) cin >> x;
    vector<int> p(n);
    iota(all(p), 0);
    sort(all(p), [&](const int &lhs, const int &rhs) {
        return a[lhs] > a[rhs];
    });
    ll sum = 0;
    int count = 0;
    for (int i = 0; i < n && sum <= a[p[i]]; i++) {
        if (e[p[i]] <= 0) {
            sum += e[p[i]];
            count++;
        }
    }
    for (int i = 0; i < n; i++) if (e[i] <= 0) count--;
    if (count != 0) {
        cout << "NO\n";
        return 0;
    }
    
    sort(all(p), [&](const int &lhs, const int &rhs) {
        return e[lhs] + a[lhs] < e[rhs] + a[rhs];
    });
    
    bool flag = true;
    for (int i : p) {
        if (e[i] <= 0) continue;
        flag &= sum <= a[i];
        sum += e[i];
    }
    
    if (flag) cout << "SI\n";
    else cout << "NO\n";
    
    return 0;
}