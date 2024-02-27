#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    map<int, ii> idx;
    bool found = false;
    for (int i = 0; i < n && !found; i++) {
        for (int j = i + 1; j < n && !found; j++) {
            int target = x - v[i] - v[j];
            if (idx.count(target)) {
                auto [k, l] = idx[target];
                cout << i + 1 << ' ' << j + 1 << ' ' << k << ' ' << l << '\n';
                found = true;
            }
        }
        for (int j = 0; j < i; j++) {
            idx[v[i] + v[j]] = {i + 1, j + 1};
        }
    }
    if (!found) cout << "IMPOSSIBLE\n";
    
    return 0;
}