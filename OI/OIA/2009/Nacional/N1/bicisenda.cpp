#include <bits/stdc++.h>

using namespace std;

const int K = 3;

char color(vector<int> &c) {
    if (all_of(begin(c), end(c), [](int k){ return k > 0; })) {
        return 'M';
    }
    for (int i = 0; i < K; i++) {
        if (c[i] && c[(i + 1) % K]) return "PVN"[i];
    }
    for (int i = 0; i < K; i++) {
        if (c[i]) return "RZA"[i];
    }
    return '.';
}

int main() {
    freopen("bicisenda.in", "r", stdin);
	freopen("bicisenda.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<vector<int>> d(n + 1, vector<int>(K));
    const map<char, int> m = {{'R', 0}, {'Z', 1}, {'A', 2}};
    while (q--) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        int i = m.at(c);
        d[a - 1][i]++;
        d[b][i]--;
    }
    
    string s;
    for (int i = 0; i < n; i++) {
        s += color(d[i]);
        for (int j = 0; j < K; j++) {
            d[i + 1][j] += d[i][j];
        }
    }
    cout << s << '\n';
    
    return 0;
}
