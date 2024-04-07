//79 pts
//pq tiene dijkstra en las tags si no entra entero?
#include <bits/stdc++.h>

using namespace std;

const int MAX_K = 301;
const int INF = 1e9;

using ii = pair<int, int>;

int main() {
    freopen("pajaros.in", "r", stdin);
	freopen("pajaros.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
    vector<vector<int>> dist(n + 1, vector<int>(MAX_K, INF));
    pq.emplace(dist[0][0] = 0, ii{0, 0});
    while (!pq.empty()) {
        auto [d, s] = pq.top();
        auto [p, h] = s;
        pq.pop();
        if (d > dist[p][h]) {
            continue;
        }
        if (p == n) {
            cout << d << '\n';
            break;
        }
        for (int j : {h - 1, h + 1}) {
            if (0 <= j && j < MAX_K) {
                int cost = abs(a[p] - j);
                if (dist[p + 1][j] > d + cost) {
                    pq.emplace(dist[p + 1][j] = d + cost, ii{p + 1, j});
                }
            }
        }
    }
    
    return 0;
}
