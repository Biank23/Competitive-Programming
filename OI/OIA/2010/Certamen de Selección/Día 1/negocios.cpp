#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
using ll = long long;
const ll INF = 1e18;
struct Cliente {
    int x, y, h, m, idx;
    bool operator<(const Cliente &o) {
        return h < o.h;
    }
};
int main() {
    freopen("negocios.in", "r", stdin);
    freopen("negocios.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<Cliente> c(n + 1);
    c[0] = {0, 0, -3, 0, 0};
    for (int i = 1; i < n; i++) {
        cin >> c[i].x >> c[i].y >> c[i].h >> c[i].m;
        c[i].idx = i;
    }
    sort(all(c));
    vector<ll> dp(n + 1, -INF);
    vector<int> par(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int dist = abs(c[i].x - c[j].x) + abs(c[i].y - c[j].y);
            if (c[j].h + dist + 3 <= c[i].h && dp[j] + c[i].m > dp[i]) {
                dp[i] = dp[j] + c[i].m;
                par[i] = j;
            }
        }
    }
    auto it = max_element(all(dp));
    cout << *it << '\n';
    int i = int(it - begin(dp));
    vector<int> ans;
    while (i != 0) {
        ans.push_back(c[i].idx);
        i = par[i];
    }
    reverse(all(ans));
    for (int idx : ans) {
        cout << idx << ' ';
    }
    
    return 0;
}