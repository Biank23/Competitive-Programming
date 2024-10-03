#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 65000;

using ii = pair<int, int>;

int p[MAX_N],n;
vector<int> g[MAX_N];
int w[MAX_N];
bitset<MAX_N> vis;
set<int> toVisit;
set<ii> bloq;

void bfs(int s, int t) {
    queue<int> q;
    q.push(s);
    g[t] = {s};
    w[t] = p[s];
    vis[s] = true;
    toVisit.erase(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        auto it = toVisit.begin();
        while (it != toVisit.end()) {
            int v = *it;
            if (bloq.count(minmax(u, v))) it++;
            else {
                g[t].push_back(v);
                w[t] += p[v];
                vis[v] = true;
                it = toVisit.erase(it);
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m;
    cin >> n >> m;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        tot += p[i];
        toVisit.insert(i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >>u >> v;
        --u,--v;
        bloq.insert(minmax(u,v));
    }
    
    vector<int> dp(tot + 1, 0);
    dp[0] = -1;
    int t = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        t++;
        bfs(i,t);
        for (int j = tot; j >= w[t]; j--) {
            if (!dp[j] && dp[j - w[t]]) dp[j] = t;
        }
    }
    ii ans = {tot + 1, -1};
    for (int i = 0; i <= tot; i++) if (dp[i]) {
        ans = min(ans, {abs(tot - 2 * i), i});
    }
    auto [diff, pos] = ans;
    cout << diff << '\n';
    while (pos != 0) {
        int c = dp[pos];
        for (int u : g[c]) {
            cout << u + 1 << ' ';
        }
        pos -= w[c];
    }
    
    return 0;
}