#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    int n = sz(s);
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) l = i, r = i + z[i];
    }
    for (int i = 0; i < n; i++) {
        cout << z[i] << ' ';
    }
    cout << '\n';
    vector<int> p(n);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
