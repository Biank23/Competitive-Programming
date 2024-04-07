//93pts
#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int K = 3;

using vi = vector<int>;
vi &operator+=(vi &v, const vi &o) {
    assert(sz(v) == sz(o));
    for (int i = 0; i < sz(v); i++) v[i] += o[i];
    return v;
}

char color(vi &c) {
    for (int i = 0; i < K; i++) {
        if (c[i] && c[(i + 1) % K]) return "PVN"[i];
    }
    for (int i = 0; i < K; i++) {
        if (c[i]) return "RZA"[i];
    }
    return '.';
}

int main() {
    freopen("mural.in", "r", stdin);
    freopen("mural.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, qh, qv;
    cin >> n >> qh >> qv;
    vector<vector<vi>> d(n + 1, vector<vi>(n + 1, vi(K, 0)));
    auto pintar = [&](int i0, int j0, int i1, int j1, int c) {
        d[i0][j0][c]++, d[i0][j1][c]--, d[i1][j0][c]--, d[i1][j1][c]++;
    };
    const map<char, int> m = {{'R', 0}, {'Z', 1}, {'A', 2}};
    while (qh--) {
        int nf, a, b;
        char c;
        cin >> nf >> c >> a >> b;
        pintar(nf - 1, a - 1, nf, b, m.at(c));
    }
    while (qv--) {
        int nc, a, b;
        char c;
        cin >> nc >> c >> a >> b;
        pintar(a - 1, nc - 1, b, nc, m.at(c));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] += d[i - 1][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] += d[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < n; j++) {
            s += color(d[i][j]);
        }
        cout << s << '\n';
    }
    return 0;
}
