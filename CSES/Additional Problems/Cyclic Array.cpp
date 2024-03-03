#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 2e5 + 10;
const int MAX_K = 18;
 
int x[MAX_N], up[MAX_K][MAX_N];
ll sz[MAX_K][MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    ll k, tot = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        tot += x[i];
    }
    
    if (tot <= k) {
        cout << "1\n";
        return 0;
    }
    
    ll sum = 0;
    int r = -1, diff = 0;
    for (int l = 0; l < n; l++) {
        diff--;
        while (sum <= k) {
            r++, diff++;
            if (r == n) r = 0;
            sum += x[r];
        }
        up[0][l] = r;
        sz[0][l] = diff;
        sum -= x[l];
    }
    
    for (int i = 1; i < MAX_K; i++) {
        for (int j = 0; j < n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
            sz[i][j] = sz[i - 1][j] + sz[i - 1][up[i - 1][j]];
        }
    }
    
    ll ans = n;
    for (int start = 0; start < n; start++) {
        ll cur_size = 0, steps = 0;
        int pos = start;
        for (int i = MAX_K - 1; i >= 0; i--) {
            if (cur_size + sz[i][pos] < n) {
                cur_size += sz[i][pos];
                pos = up[i][pos];
                steps += 1<<i;
            }
        }
        ans = min(ans, steps + 1);
    }
    cout << ans << '\n';
    
}