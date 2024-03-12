#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int TT;
	cin >> TT;
	for (int tt = 1 ; tt <= TT; tt++) {
		int n;
        string s;
        cin >> n >> s;
        vector<bool> p(n, 0);
        int op = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                p[i] = 1;
                op++;
                for (int j = i; j < n; j += i + 1) {
                    s[j] = '1' + '0' - s[j];
                }
            }
        }
        int q;
        cin >> q;
        ll ans = 0;
        for (int i = 0; i < q; i++) {
            int b;
            cin >> b;
            --b;
            if (p[b]) op--;
            else op++;
            p[b] = !p[b];
            ans += op;
        }
        cout << "Case #" << tt << ": " << ans << '\n';
	}
}
