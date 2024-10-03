#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

pair<string, int> desescapar(string s){
    int n = sz(s);
    string r = "";
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '$') return {s, 0};
        if (s[i] != 'x') r += s[i];
        else {
            flag = 2;
            if (i + 1 < n && s[i + 1] == 'x') r += 'x';
            else if (i + 1 < n && s[i + 1] == 'p') r += '$';
            else return {s, 0};
            i++;
        }
    }
    return {r, flag};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string res = "NOSTRING";
    int c = 0;
    string s;
    cin >> s;
    int flag = 2;
    while (flag == 2) {
        tie(s, flag) = desescapar(s);
        if (flag) {
            if (res == "NOSTRING") res = s;
            else res = min(res, s);
            c++;
        }
    }
    cout << c << '\n' << res << '\n';
    
    return 0;
}