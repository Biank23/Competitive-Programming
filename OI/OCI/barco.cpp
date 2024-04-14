#include <bits/stdc++.h>

using namespace std;


#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ii = pair<int, int>;
#define fst first
#define snd second

const int MAX_N = 1000;
const int INF = 1e6;

int c[MAX_N][MAX_N][4];
ii p[MAX_N][MAX_N];

struct Query {
    int x1, y1, x2, y2;
};

ii find(ii x) {
    if(p[x.fst][x.snd]!=x) p[x.fst][x.snd]=find(p[x.fst][x.snd]);
    return p[x.fst][x.snd];
}

void unite(ii x, ii y) {
    x = find(x), y = find(y);
    if (x != y) {
        p[x.fst][x.snd] = y;
    }
}

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int op[] = {2, 3, 0, 1};

void update(int x, int y, int i, int v) {
    c[x][y][i] += v;
    if (!c[x][y][i] && !c[x + dx[i]][y + dy[i]][op[i]]) {
        ii a = {x, y}, b = {x + dx[i], y + dy[i]};
        unite(a, b);
    }
}

void update(Query q, int v) {
    for (int y = q.y1; y <= q.y2; y++) {
        update(q.x1, y, 0, v);
        update(q.x2, y, 2, v);
    }
    for (int x = q.x1; x <= q.x2; x++) {
        update(x, q.y1, 1, v);
        update(x, q.y2, 3, v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<Query> v(q);
    vector<int> t(q);
    for (int i = 0; i < q; i++) {
        cin >> t[i] >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
        v[i].x1--, v[i].y1--, v[i].x2--, v[i].y2--;
        if (t[i] == 2) update(v[i], 1);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = {i, j};
        }
    }
    update(Query{0, 0, n - 1, m - 1}, INF);
    for (int i = 0; i < n; i++) {
        update(Query{i, 0, i, m - 1}, 0);
    }
    for (int i = 0; i < m; i++) {
        update(Query{0, i, n - 1, i}, 0);
    }
    
    reverse(all(v));
    reverse(all(t));
    vector<bool> ans;
    for (int i = 0; i < q; i++) {
        if (t[i] == 1) {
            ii x = {v[i].x1, v[i].y1}, y = {v[i].x2, v[i].y2};
            ans.push_back(find(x) == find(y));
        } else {
            update(v[i], -1);
        }
    }
    
    reverse(all(ans));
    for (int i = 0; i < sz(ans); i++) {
        if (ans[i]) {
            cout << "SI\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
