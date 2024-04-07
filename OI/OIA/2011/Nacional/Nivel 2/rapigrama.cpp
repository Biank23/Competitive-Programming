#include <bits/stdc++.h>

using namespace std;

bool find(string &s, vector<string> &v) {
    for (string &r : v) {
        if (r.find(s) != -1) return true;
    }
    return false;
}

int main() {
    freopen("rapigrama.in", "r", stdin);
	freopen("rapigrama.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<string> v1(n), v2(n, string(n, '-'));
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
        for (int j = 0; j < n; j++) {
            v2[j][i] = v1[i][j];
        }
    } 
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        string r(s.rbegin(), s.rend());
        if (find(s, v1)) {
            cout << i + 1 << " E\n";
        } else if (find(r, v1)) {
            cout << i + 1 << " O\n";
        } else if (find(s, v2)) {
            cout << i + 1 << " S\n";
        } else if (find(r, v2)) {
            cout << i + 1 << " N\n";
        }
    }
    
    return 0;
}
