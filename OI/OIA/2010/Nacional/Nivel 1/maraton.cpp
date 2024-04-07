#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("maraton.in", "r", stdin);
	freopen("maraton.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    const int K = 10;
    vector<int> ans(K, 0);
    for (int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;
        --c;
        if (ans[c] == 0) {
            ans[c] = a;
        }
    }
    for (int i = 0; i < K; i++) {
        cout << i + 1 << ' ' << ans[i] << '\n';
    }
    
    return 0;
}
