#include <bits/stdc++.h>

using namespace std;

char pintar(char pos, char color) {
    if (pos == '.') {
        return color;
    }
    if (pos > color) {
        swap(pos, color);
    }
    if (pos == 'R' && color == 'Z') {
        return 'P';
    }
    if (pos == 'A' && color == 'R') {
        return 'N';
    }
    if (pos == 'A' && color == 'Z') {
        return 'V';
    }
    return pos;
}

int main() {
    freopen("mural.in", "r", stdin);
	freopen("mural.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, qh, qv;
    cin >> n >> qh >> qv;
    vector<string> s(n, string(n, '.'));
    while (qh--) {
        int nf, a, b;
        char c;
        cin >> nf >> c >> a >> b;
        nf--, a--;
        for (int i = a; i < b; i++) {
            s[nf][i] = pintar(s[nf][i], c);
        }
    }
    while (qv--) {
        int nc, a, b;
        char c;
        cin >> nc >> c >> a >> b;
        nc--, a--;
        for (int i = a; i < b; i++) {
            s[i][nc] = pintar(s[i][nc], c);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << '\n';
    }
    return 0;
}
