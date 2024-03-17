#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) int(x.size())

using ll = long long;

using ii = pair<int, int>;
#define fst first
#define snd second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ii> v(n);
        for (auto &[b, a] : v) {
            cin >> a >> b;
        }
        sort(all(v));
        int res = 0;
        for (int l = 0; l < n; l++) {
            priority_queue<int> pq;
            ll sum = 0;
            for (int r = l; r < n; r++) {
                pq.push(v[r].snd);
                sum += v[r].snd;
                while (!pq.empty() && sum + v[r].fst - v[l].fst > k) {
                    sum -= pq.top();
                    pq.pop();
                }
                res = max(res, sz(pq));
            }
        }
        cout << res << '\n';
    }
    
    return 0;
}