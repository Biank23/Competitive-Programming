#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

string sum(string a, string b) {
    int n = sz(a);
    string c(n, '0');
    for (int i = 0; i < n - 1; i++) {
        int s = (a[i] - '0') + (b[i] - '0') + (c[i] - '0');
        c[i] = char('0' + s % 10);
        c[i + 1] += s / 10;
    }
    return c;
}

int hallarx(string &a, string &b, string &c) {
    vector<string> s = {a, b, c};
    int n = 1;
    for (int i = 0; i < 3; i++) {
        n = max(n, sz(s[i]) + 1);
        reverse(all(s[i]));
    }
    for (int i = 0; i < 3; i++) {
        s[i].resize(n, '0');
    }
    pair<int, int> pos;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'x') {
                pos = {i, j};
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        s[pos.first][pos.second] = char('0' + i);
        if (sum(s[0], s[1]) == s[2]) return i;
    }
    return -1;
}
