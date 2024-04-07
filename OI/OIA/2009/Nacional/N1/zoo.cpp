#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e4 + 9;

int g[MAX_N], masc[MAX_N], fem[MAX_N];

int main() {
    freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int e, m, f;
    cin >> e >> m >> f;
    while (e--) {
        int c, t;
        cin >> c >> t;
        g[c] = t;
    }
    for (int i = 0; i < m; i++) {
        cin >> masc[i];
    }
    for (int i = 0; i < f; i++) {
        cin >> fem[i];
    }
    int n = min(m, f);
    int same = 0, lost = 0;
    int curr = 0, maxi = 0;
    for (int i = 0; i < n; i++) {
        if (abs(g[masc[i]] - g[fem[i]]) < 4) {
            curr++;
            if (masc[i] == fem[i]) same++;
        } else {
            curr = 0;
            lost++;
        }
        maxi = max(maxi, curr);
    }
    cout << same << ' ' << lost << ' ' << maxi << '\n';
    
    return 0;
}
