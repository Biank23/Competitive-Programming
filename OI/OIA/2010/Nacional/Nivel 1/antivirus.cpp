#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("antivirus.in", "r", stdin);
	freopen("antivirus.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    char a, b;
    string s;
    cin >> n >> a >> b >> s;
    int ans = n;
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == a && s[i] == b && s[i + 1] == a) {
            s[i] = 0, ans--;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        if (s[i]) cout << s[i];
    }
    cout << '\n';
    
    return 0;
}
