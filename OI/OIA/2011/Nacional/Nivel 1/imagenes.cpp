#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

string comp(string s) {
    string t = "";
    int cont = 0;
    char prev = '-';
    s += '-';
    for (char &c : s) {
        if (c == prev) {
            cont++;
        } else {
            if (cont > 4) {
                t += '(';
                t += prev;
                t += to_string(cont);
                t += ')';
            } else {
                t += string(cont, prev);
            }
            cont = 1, prev = c;
        }
    }
    return t;
}

string decomp(string s) {
    string t = "";
    int cont = 0;
    bool flag = false;
    char prev = '-';
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '(') {
            i++;
            prev = s[i], flag = true;
        } else if (s[i] == ')') {
            t += string(cont, prev);
            cont = 0, flag = false;
        } else if (flag) {
            cont = cont * 10 + s[i] - '0';
        } else {
            t += s[i];
        }
    }
    return t;
}

int main() {
    freopen("imagenes.in", "r", stdin);
	freopen("imagenes.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s, t;
    cin >> s >> t;
    cout << comp(s) << '\n';
    cout << decomp(t) << '\n';
    
    return 0;
}
