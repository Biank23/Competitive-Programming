#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

string standardToRXCX(string s) {
    int p = 0;
    while ('A' <= s[p] && s[p] <= 'Z') p++;
    string column = s.substr(0, p);
    int col = 0;
    for (char c : column) {
        col = col * 26 + (c - 'A' + 1);
    }
    string row = s.substr(p);
    return "R" + row + "C" + to_string(col);
    
}

string RXCXtoStandand(string s) {
    int p = 0;
    while (s[p] != 'C') p++;
    int col = stoi(s.substr(p + 1)) - 1;
    string column = "";
    while (col >= 0) {
        column += char('A' + col % 26);
        col = col / 26 - 1;
    }
    reverse(all(column));
    string row = s.substr(1, p - 1);
    return column + row;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        int p = 0;
        while ('A' <= s[p] && s[p] <= 'Z') p++;
        while (p < sz(s) && s[p] != 'C') p++;
        if (p == sz(s)) cout << standardToRXCX(s) << '\n';
        else cout << RXCXtoStandand(s) << '\n';
        
    }

    return 0;
}
