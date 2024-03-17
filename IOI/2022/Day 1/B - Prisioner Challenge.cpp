#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ii = pair<int, int>;
using vi = vector<int>;

const int X = 20;
const int MAX_N = 5588;
const vi c = {3, 3, 3, 3, 3, 2, 2, 1, 1};

vector<vi> s(X + 1);
int n;

map<ii, int> M;
 
int m(int h, int k) {
    ii state = {h, k};
    if (!M.count(state)) {
        M[state] = sz(M);
    }
    return M[state];
}

void put(int i, int j, int v) {
    if (j <= n) s[i][j] = v;
}

void solve(int L = 1, int R = MAX_N, int h = 0, int k = 0) {
    int t = h & 1;
    int x = m(h - 1, k);
    int sz = (R - L - 1) / c[h];
    put(x, 0, t);
    put(x, L, -t -1);
    if (sz > 0) {
        for (int i = 0; i < c[h]; i++) {
            int S = L + sz * i + 1;
            int E = L + sz * (i + 1);
            int y = m(h, i);
            for (int j = L; j < S; j++) {
                put(y, j, t - 2);
            }
            for (int j = S; j <= E; j++) {
                put(x, j, y);
            }
            for (int j = E + 1; j <= R; j++) {
                put(y, j, -t - 1);
            }
            solve(S, E, h + 1, i);
        }
    }
    put(x, R, t - 2);
}

vector<vi> devise_strategy(int N) {
    n = N;
    for (int i = 0; i <= X; i++) {
        s[i].assign(n + 1, 0);
    }
    solve();
    return s;
}
