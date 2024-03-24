#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> v[2];
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v[i % 2].push_back(a);
        }
        for (int i = 0; i < 2; i++) {
            sort(all(v[i]));
        }
        auto &even = v[0], &odd = v[1];
        int i = 0, j = sz(odd) - 1;
        while (k > 0 && i < sz(even) && j >= 0 && odd[j] > even[i]) {
            swap(odd[j], even[i]);
            i++, j--, k--;
        }
        if (n == 2 && k % 2) {
            swap(odd.front(), even.front());
        }
        ll ans = 0;
        for (auto [p, s] : vector<pair<int, int>>{{0, 1}, {1, -1}}) {
            for (int a : v[p]) ans += a * s;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
