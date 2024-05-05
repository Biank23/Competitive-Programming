#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ii = pair<int, int>;
#define fst first
#define snd second

const int MAX_N = 1 << 17;

int par[MAX_N], size[MAX_N];
int components;
vector<pair<int&, int>> history;

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i, size[i] = 1;
    }
    components = n;
}

int find(int x) {
    if (x != par[x]) return find(par[x]);
    return x;
}

void save(int &x) {
    history.emplace_back(x, x);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    save(par[y]), save(size[x]), save(components);
    par[y] = x, size[x] += size[y], components--;
}

void rollback(int time) {
    while (sz(history) > time) {
        history.back().fst = history.back().snd;
        history.pop_back();
    }
}

vector<ii> st[2 * MAX_N];

void update(int s, int e, ii q, int l = 0, int r = MAX_N, int u = 1) {
    if (e <= l || r <= s) return;
    if (s <= l && r <= e) {
        st[u].push_back(q);
        return;
    }
    int m = (l + r) / 2;
    update(s, e, q, l, m, 2 * u);
    update(s, e, q, m, r, 2 * u + 1);
}

int ans[MAX_N];

void dfs(int u) {
    int time = sz(history);
    for (auto [x, y] : st[u]) {
        unite(x, y);
    }
    if (u < MAX_N) {
        dfs(2 * u), dfs(2 * u + 1);
    } else {
        ans[u - MAX_N] = components;
    }
    rollback(time);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    map<ii, int> time;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (u > v) swap(u, v);
        time[{u, v}] = 0;
    }
    for (int i = 1; i <= k; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        --u, --v;
        if (u > v) swap(u, v);
        ii e = {u, v};
        if (t == 1) {
            time[e] = i;
        } else {
            update(time[e], i, e);
            time.erase(e);
        }
    }
    for (auto [edge, l] : time) {
        update(l, k + 1, edge);
        
    }
    init(n);
    dfs(1);
    for (int i = 0; i <= k; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
