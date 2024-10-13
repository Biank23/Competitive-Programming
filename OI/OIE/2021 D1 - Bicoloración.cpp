#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ii = pair<int, int>;

struct Edge {
    int u, v, w;
};

const int INF = 2e9 + 20;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<Edge> graph(m);
        for (int i = 0; i < m; i++) {
            cin >> graph[i].u >> graph[i].v >> graph[i].w;
        }
        auto check = [&](int D) {
            vector<vector<ii>> adj(n);
            for (int i = 0; i < m; i++) {
                if (graph[i].w < D) {
                    adj[graph[i].u].emplace_back(graph[i].v, graph[i].w);
                    adj[graph[i].v].emplace_back(graph[i].u, graph[i].w);
                }
            }
            vector<bool> visited(n, false), color(n);
            stack<int> st;
            for (int i = 0; i < n; i++) {
                if (visited[i]) continue;
                color[i] = true, visited[i] = true;
                st.push(i);
                while (!st.empty()) {
                    int u = st.top();
                    st.pop();
                    for (auto [v, w] : adj[u]) {
                        if (visited[v]) continue;
                        color[v] = !color[u], visited[v] = true;
                        st.push(v);
                    }
                }
            }
            for (int u = 0; u < n; u++) {
                for (auto [v, w] : adj[u]) if (color[u] == color[v]) return false;
                if (sz(adj[u]) < 2) continue;
                ii minW = {INF, INF}, sndMinW = {INF, INF};
                for (auto [v, w] : adj[u]) minW = min(minW, ii{w, v});
                for (auto [v, w] : adj[u]) if (v != minW.second) sndMinW = min(sndMinW, ii{w, v});
                if (minW.first + sndMinW.first < D) return false;
            }
            return true;
        };
        int lo = 0, hi = INF;
        while (hi - lo > 1) {
            int mid = (hi - lo) / 2 + lo;
            if (check(mid)) lo = mid;
            else hi = mid;
        }
        if (hi == INF) cout << "INF\n";
        else cout << lo << '\n';
    }
    
    return 0;
}
