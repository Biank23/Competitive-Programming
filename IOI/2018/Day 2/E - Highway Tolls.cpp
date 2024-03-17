#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;

ll ask(const vi &w);

void answer(int s, int t);

void find_pair(int n, vi u, vi v, int /*a*/, int /*b*/) {
    vector<vector<ii>> adj(n);
    int m = sz(u);
    for (int i = 0; i < m; i++) {
        adj[u[i]].emplace_back(v[i], i);
        adj[v[i]].emplace_back(u[i], i);
    }
    
    vi w(m, 0);
    ll D = ask(w);
    
    int low = -1, high = m;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        for (int i = 0; i < m; i++) {
            w[i] = i <= mid;
        }
        if (ask(w) != D) high = mid;
        else low = mid;
    }
    
    int e = high;
    int start[2] = {u[e], v[e]};
    vi d[2];
    for (int i = 0; i < 2; i++) {
        d[i].assign(n, -1);
        queue<int> q;
        q.push(start[i]);
        d[i][start[i]] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto [y, idx] : adj[x]) {
                if (d[i][y] == -1) {
                    q.push(y);
                    d[i][y] = d[i][x] + 1;
                }
            }
        }
    }
    
    int ans[2];
    for (int i = 0; i < 2; i++) {
        vi node(n, 0), edge(m, -1), dist(n, -1);
        queue<int> q;
        int c = 0;
        q.push(start[i]);
        dist[start[i]] = 0;
        
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto [y,idx] : adj[x]) {
                if (d[i][y] < d[i ^ 1][y] && dist[y] == -1) {
                    dist[y] = dist[x] + 1;
                    node[c] = y;
                    edge[idx] = c++;
                    q.push(y);
                } else if((d[i][y] >= d[i ^ 1][y] && idx != e) || dist[y] == dist[x] + 1) {
                    edge[idx] = n;
                }
            }
        }
        
        int lo = -1, hi = c;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            for (int j = 0; j < m; j++) {
                w[j] = edge[j] >= mid;
            }
            if(ask(w) != D) lo = mid;
            else hi = mid;
        }
        if (lo == -1) ans[i] = start[i];
        else ans[i] = node[lo];
    }
    
    answer(ans[0], ans[1]);
}
