#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int INF = 1e9 + 20;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int n;
        cin >> n;
        vector<int> a{INF};
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x != a.back()) {
                a.push_back(x);
            }
        }
        a.push_back(INF);
        int count = 0;
        for (int i = 1; i < sz(a) - 1; i++) {
            if (a[i - 1] > a[i] && a[i] < a[i + 1]) count++;
        }
        if (count == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
