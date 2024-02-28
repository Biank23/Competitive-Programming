#include <bits/stdc++.h>
 
using namespace std;
 
const int BLOCK_SIZE = 450;
 
struct Query {
    int l, r, idx;
    bool operator<(const Query &o) {
        if (l / BLOCK_SIZE != o.l / BLOCK_SIZE) {
            return l < o.l;
        }
        if (l / BLOCK_SIZE & 1) {
            return r < o.r;
        }
        return r > o.r;
    }
};
 
const int MAX_N = 2e5 + 9;
 
vector<Query> q;
int timer = -1, val[MAX_N];
vector<int> order, adj[MAX_N];
 
void dfs(int u, int p = -1) {
    q[u].l = ++timer;
    order.push_back(val[u]);
    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
    q[u].r = timer;
}
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    q.resize(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        c[i] = val[i];
        q[i].idx = i;
    }
    sort(all(c));
    c.erase(unique(all(c)), end(c));
    
    for (int i = 0; i < n; i++) {
        val[i] = int(lower_bound(all(c), val[i]) - begin(c));
    }
    
    for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
    
    dfs(0);
    sort(all(q));
    
    vector<int> freq(n, 0);
    int distinctValues = 0;
    
    auto add = [&](int i) {
        freq[order[i]]++;
        if (freq[order[i]] == 1) {
            distinctValues++;
        }
    };
    
    auto erase = [&](int i) {
        freq[order[i]]--;
        if (freq[order[i]] == 0) {
            distinctValues--;
        }
    };
    
    vector<int> res(n);
    int curL = 0, curR = -1;
    for (auto [l, r, idx] : q) {
        while (l < curL) {
            add(--curL);
        }
        while (r > curR) {
            add(++curR);
        }
        while (l > curL) {
            erase(curL++);
        }
        while (r < curR) {
            erase(curR--);
        }
        res[idx] = distinctValues;
    }
    
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }    
    
    return 0;
}