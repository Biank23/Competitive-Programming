#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int TT;
	cin >> TT;
	for (int tt = 1 ; tt <= TT; tt++) {
		int n, q;
        string s;
        cin >> n >> s >> q;
        vector<bool> p(n, 0);
        for (int i = 0; i < q; i++) {
            int b;
            cin >> b;
            --b;
            p[b] = !p[b];
        }
        for (int i = 0; i < n; i++) {
            if (p[i]) {
                for (int j = i; j < n; j += i + 1) {
                    s[j] = '1' + '0' - s[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans++;
                for (int j = i; j < n; j += i + 1) {
                    s[j] = '1' + '0' - s[j];
                }
            }
        }
        cout << "Case #" << tt << ": " << ans << '\n';
	}
}
