#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

vector<string> gravitas(vector<string> &g) {
    int n = sz(g), m = sz(g[0]);
    vector<int> pos(m, n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '<') {
                assert(j + 1 < m);
                int k = min(pos[j], pos[j + 1]);
                if (k > i) {
                    g[i][j] = '.', g[i][j + 1] = '.';
                    assert(k - 1 >= 0);
                    g[k - 1][j] = '<', g[k - 1][j + 1] = '>';
                    pos[j] = pos[j + 1] = k - 1;
                }
            } else if (g[i][j] == 'V') {
                assert(i - 1 >= 0);
                int k = pos[j];
                if (k > i) {
                    g[i][j] = '.', g[i - 1][j] = '.';
                    assert(k - 2 >= 0);
                    g[k - 1][j] = 'V', g[k - 2][j] = 'A';
                    pos[j] = k - 2;
                }
            }
        }
    }
    return g;
}
