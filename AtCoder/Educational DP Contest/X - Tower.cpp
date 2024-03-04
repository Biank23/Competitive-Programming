#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)

using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> w(n), s(n), v(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> s[i] >> v[i];
        p[i] = i;
    }
    sort(all(p), [&](const int &a, const int &b){
        return w[a] + s[a] < w[b] + s[b];
    });

    int x = p.back();
    int m = w[x] + s[x];
    vector<ll> dp(m + 1, 0);
    for (int i : p) {
        for (int j = s[i] + w[i]; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << *max_element(all(dp)) << '\n';
    
    return 0;
}
