#include <bits/stdc++.h>

using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

const map<char, int> id = {{'R', 0}, {'Z', 1}, {'A', 2}};

struct Pincelada {
    bool tipo;
    int color, pos, l, r;
    bool recorrer(const function<bool(int, int, int)> &f) {
        for (int i = l; i < r; i++) {
            if (!f(tipo ? i : pos, tipo ? pos : i, color)) return false;
        }
        return true;
    }

    friend istream& operator>>(istream &is, Pincelada &p) {
        char t, c;
        is >> t >> p.pos >> c >> p.l >> p.r;
        --p.l, --p.pos;
        p.tipo = t == 'C', p.color = id.at(c);
        return is;
    }
};

int solve(const vector<vector<bitset<3>>> &b, vector<Pincelada> &p) {
    int n = sz(p);
    for (int i = 0; i < n; i++) {
        if (!p[i].recorrer([&b](int x, int y, int c) {
            return b[x][y][c];
        })) return i;
    }
    return n;
}

template<typename T>
void rotate(vector<vector<T>> &mat) {
    int n = sz(mat);
    assert(n == sz(mat[0]));
    for (int i = 0; i < n; i++) {
        reverse(all(mat[i]));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

int main() {
    freopen("copia.in", "r", stdin);
    freopen("copia.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T, n;
    cin >> T >> n;
    vector<vector<bitset<3>>> b(T, vector<bitset<3>>(T));
    for (int i = 0; i < n; ++i) {
        Pincelada p;
        cin >> p;
        p.recorrer([&b](int x, int y, int c) {
            return b[x][y][c] = true;
        });
    }

    int m;
    cin >> m;
    vector<Pincelada> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans = max(ans, solve(b, p));
        rotate(b);
    }
    cout << ans << '\n';

    return 0;
}
