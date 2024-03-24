#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ii = pair<int, int>;
#define fst first
#define snd second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<ii> v[3];
        vector<ii> aCopy;
        for (int i = 0; i < 3; i++) {
            v[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> v[i][j].fst;
                v[i][j].snd = j;
            }
            if (i == 0) aCopy = v[i];
            sort(all(v[i]));
        }
        auto a = v[0], b = v[1], c = v[2];
        int j = 0, k = 0;
        vector<bool> used(n, false);
        int ans = 0;
        priority_queue<ii> pqA, pqB;
        auto clear = [&](priority_queue<ii> &pq){
            while (!pq.empty() && used[pq.top().snd]) {
                pq.pop();
            }
        };
        for (int i = 0; i < n; i++) {
            while (j < n && a[j].fst <= c[i].fst) {
                pqA.push(a[j]);
                j++;
            }
            while (k < n && b[k].fst <= c[i].fst) {
                pqB.emplace(aCopy[b[k].snd].fst, b[k].snd);
                k++;
            }
            clear(pqA), clear(pqB);
            if (!pqA.empty()) {
                used[pqA.top().snd] = true;
            } else if (!pqB.empty()) {
                used[pqB.top().snd] = true;
                ans++;
            } else {
                ans = -1;
                break;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
