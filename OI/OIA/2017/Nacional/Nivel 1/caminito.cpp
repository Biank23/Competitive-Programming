#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

void caminito(string &s) {
    int n = sz(s);
    if (s[0] == 'R') {
        if (n == 1 || s[1] != 'B') s[0] = 'B';
        else s[0] = 'N';
    }
    for (int i = 1; i < n; i++) {
        if (s[i] != 'R') continue;
        if (i == n - 1 || s[i + 1] == 'R' || s[i - 1] == s[i + 1]) {
            if (s[i - 1] != 'B') s[i] = 'B';
            else s[i] = 'N';
        } else {
            s[i] = 'N' ^ 'G' ^ 'B' ^ s[i - 1] ^ s[i + 1];
        }
    }
}
