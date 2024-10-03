#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> pos(m); 
    for (int i = 0; i < n; i++) {
        int last = 0;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) last = j;
        }
        pos[last].push_back(i);
    }
    vector<int> x(m);
    for (int j = 0; j < m; j++) {
        set<ll> vals;
        for (int i : pos[j]) {
            ll Exp = 0;
            for (int k = 0; k < j; k++) Exp += (ll) x[k] * a[i][k];
            if (Exp % a[i][j] == 0 && -Exp / a[i][j] >= 0) {
                assert(Exp + (-Exp / a[i][j]) * a[i][j] == 0);
                vals.insert(-Exp / a[i][j]);
            }
        }
        x[j] = 0;
        for (ll v : vals) {
            if (v == x[j]) x[j]++;
            else break;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << x[i] << ' ';
    }
    
    return 0;
}