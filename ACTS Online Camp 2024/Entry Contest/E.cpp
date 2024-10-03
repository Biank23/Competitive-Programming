#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1009;

vector<int> adj[MAX_N];
int dist[MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, s;
    cin >> n >> s;
    --s;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        adj[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> adj[i][j];
            --adj[i][j];
        }
    }

    memset(dist, -1, sizeof dist);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    int maxi = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        maxi = dist[u];
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << maxi << '\n';
    for (int i = 0; i < n; i++) {
        if (dist[i] == maxi) cout << i + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
