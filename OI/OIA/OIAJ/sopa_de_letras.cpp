#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

bool search(string &s, vector<string> &mat) {
    int k = sz(s);
    for (string &t : mat) {
        int n = sz(t);
        for (int i = 0; i <= n - k; i++) {
            if (t.substr(i, k) == s) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> mat[2];
    for (int i = 0; i < 2; i++) {
        mat[i].assign(n, string(m, '-'));
        swap(n, m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[0][i][j];
            mat[1][j][i] = mat[0][i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        string s[2];
        cin >> s[0];
        s[1] = string(s[0].rbegin(), s[0].rend());
        bool flag = false;
        for (int j = 0; j < 4; j++) {
            if (search(s[j / 2], mat[j % 2])) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "SI\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
