#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int MAX_N = 3e5 + 9;

vector<int> adj[MAX_N];
bitset<MAX_N> done;
int cant[2][3], t[MAX_N];

int main() {
    freopen("repetidores.in", "r", stdin);
	freopen("repetidores.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, m;
        char c;
        cin >> a >> c >> m;
        --a;
        t[a] = c - 'A';
        for (int j = 0; j < m; j++) {
            int b;
            cin >> b;
            --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    
    queue<int> q;
    if (n != 0) {
        q.push(0);
        done[0] = true;
    }
    bool p = 0;
    while (!q.empty()) {
        int s = sz(q);
        while (s--) {
            int u = q.front();
            q.pop();
            cant[p][t[u]]++;
            for (int v : adj[u]) {
                if (!done[v]) {
                    q.push(v);
                    done[v] = true;
                }
            }
        }
        p ^= 1;
    }
    
    tuple<int, char, char> ans = {n, 'F', 'F'};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) ans = min(ans, {n - cant[0][i] - cant[1][j], 'A' + i, 'A' + j});
        }
    }
    auto [cost, t1, t2] = ans;
    assert(t1 != 'F');
    cout << cost << ' ' << t1 << ' ' << t2 << '\n';
    
    return 0;
}
