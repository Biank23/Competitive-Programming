#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 2e5 + 9;
const int MAX_H = 20;
const int INF = 1e9;
 
vector<int> adj[MAX_N];
bitset<MAX_N> done;
int sz[MAX_N];

int getSize(int u, int p = -1) {
	sz[u] = 1;
	for (int v : adj[u]) {
		if (v != p && !done[v]) {
			sz[u] += getSize(v, u);
		}
	}
	return sz[u];
}
 
int findCentroid(int u, int size, int p = -1) {
	for (int v : adj[u]) {
		if (v != p && !done[v] && sz[v] > size / 2) {
            return findCentroid(v, size, u);
		}
	}
	return u;
}
 
int height[MAX_N], par[MAX_N];
int dist[MAX_H][MAX_N], best[MAX_N];

void dfs(int u, int h, int p = -1, int d = 0) {
    dist[h][u] = d;
    for (int v : adj[u]) {
        if (v != p && !done[v]) {
            dfs(v, h, u, d + 1);
        }
    }
}

void build(int u, int h = 0, int p = -1) {
    int size = getSize(u);
    u = findCentroid(u, size);
	done[u] = true;
    height[u] = h;
    par[u] = p;
    dfs(u, h);
	for (int v : adj[u]) {
		if (!done[v]) {
			build(v, h + 1, u);
		}
	}
}

void update(int u) {
    for (int v = u, h = height[u]; v != -1; v = par[v], h--) {
        best[v] = min(best[v], dist[h][u]);
    }
}

int query(int u) {
    int minDist = INF;
    for (int v = u, h = height[u]; v != -1; v = par[v], h--) {
        minDist = min(minDist, best[v] + dist[h][u]);
    }
    return minDist;
}

void init(int n) {
    for (int i = 0; i < n; i++) {
        best[i] = INF;
    }
    done.reset();
    build(0);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	int n, d;
	cin >> n >> d;
    
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
        --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

    queue<int> q;
    q.push(0);
    done[0] = true;

    stack<int> s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        s.push(u);
        for (int v : adj[u]) {
            if (!done[v]) {
                q.push(v);
                done[v] = true;
            }
        }
    }

    init(n);
    vector<int> offices;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (query(u) >= d) {
            offices.push_back(u);
            update(u);
        }
    }

    cout << ssize(offices) << '\n';
    for (int u : offices) {
        cout << u + 1 << ' ';
    }

	return 0;
}