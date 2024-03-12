#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;

const ll INF = 2e18;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int TT;
	cin >> TT;
	for (int tt = 1; tt <= TT; tt++) {
        cout << "Case #" << tt << ": ";
        
		int n;
		cin >> n;
		
		vector<ll> a(2 * n - 1);
		for (int i = 0; i < 2 * n - 1; i++) {
			cin >> a[i];
		}
        
        if (n == 1) {
            cout << "1\n";
			continue;
		}
		
        sort(all(a));
        ll ans = INF;
		for (ll k : {a[0] + end(a)[-1], a[0] + end(a)[-2], a[1] + end(a)[-1]}) {
            int l = 0, r = 2 * n - 2;
            int count = 0;
            ll skip = -1;
            while (l <= r) {
                if (l != r && a[l] + a[r] == k) {
                    l++, r--;
                } else {
                    count++;
                    if (a[l] + a[r] > k) {
                        skip = a[r];
                        r--;
                    } else {
                        skip = a[l];
                        l++;
                    }
                }
            }
            if (count == 1 && k > skip) ans = min(ans, k - skip);
        }
        if (ans == INF) cout << "-1\n";
        else cout << ans << '\n';
	}
}