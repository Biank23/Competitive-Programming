#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

pair<char, int> find(string &s) {
    int n = sz(s);
    for (int i = 0; i < n; i++) {
        if (s[i] != '*') return {s[i], i % 3};
    }
    assert(false);
}

int main() {
    freopen("baldosas.in", "r", stdin);
	freopen("baldosas.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    const string colores = "RAV";
    auto [c, j] = find(s);
    string tipos(3, '-');
    tipos[j] = c;
    for (int i = 0; i < 3; i++) {
        if (colores[i] != c) {
            j = (j + 1) % 3;
            tipos[j] = colores[i];
        }
    }
    int n = sz(s);
    for (int i = 0; i < n; i++) {
        s[i] = tipos[i % 3];
    }
    cout << s << '\n';
    
    return 0;
}
