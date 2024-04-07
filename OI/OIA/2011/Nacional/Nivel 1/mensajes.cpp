#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("mensajes.in", "r", stdin);
	freopen("mensajes.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    string s = "";
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s += c;
    }
    
    string t;
    cin >> t;
    string r(t.rbegin(), t.rend());
    if (s.find(t) != -1) {
        cout << "SI\nI\n";
    } else if (s.find(r) != -1) {
        cout << "SI\nD\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}
