#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v[2];
        for (int i = 0; i < n * m; i++) {
            int a;
            cin >> a;
            v[a % 2].push_back(a);
        }
        int E = sz(v[0]), O = sz(v[1]);
        int diff = abs(E - O);
        int parity = (n * m) % 2;
        
        if (diff != parity) {
            cout << "-1\n";
            continue;
        }
        
        if (E < O) swap(v[0], v[1]);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int p = (i + j) % 2;
                cout << v[p].back() << ' ';
                v[p].pop_back();
            }
            cout << '\n';
        }
    }
    
    return 0;
}
