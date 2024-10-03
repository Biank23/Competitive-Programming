#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x),end(x)

typedef vector<int> vi;

const int MAX_N = 1e5 + 9;

int val(char c) {
    if (c == 'a') return 0;
    if (c == 'e') return 1;
    if (c == 'i') return 2;
    if (c == 'o') return 3;
    if (c == 'u') return 4;
    assert(false);
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    string s;
    cin >> n >> s;
    vector<vi> sig(n + 2);
    sig[n + 1] = vi(5, n + 1);
    vi best(n + 2);
    best[n + 1] = n + 1;
    for (int i = n; i >= 0; i--) {
        sig[i] = sig[i + 1];
        if (i < n) sig[i][val(s[i])] = i + 1;
        best[i] = *max_element(all(sig[i]));
    }
    const int k = 19;
    vector<vi> up(k, vi(n + 2));
    for (int i = 0; i < n + 2; i++) {
        up[0][i] = best[i];
    }
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < n + 2; j++) {
            up[i + 1][j] = up[i][up[i][j]];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l,r;
        cin >> l >> r;
        --l;
        int ans = 0;
        for (int i = k - 1; i >= 0; i--) {
            if (up[i][l] <= r) {
                l = up[i][l];
                ans += 1 << i;
            }
        }
        cout << ans + 1 << '\n';
    }
    
    return 0;
}