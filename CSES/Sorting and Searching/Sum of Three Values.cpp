#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> v(n), idx(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        idx[i] = i;
    }
    sort(all(idx), [&](const int &lhs, const int &rhs) {
        return v[lhs] < v[rhs];
    });
    
    bool found = false;
    for (int l = 0; l < n - 2 && !found; l++) {
        int r = n - 1, target = x - v[idx[l]];
        for (int m = l + 1; m < r && !found; m++) {
            while (r - 1 > m && v[idx[m]] + v[idx[r]] > target) {
                --r;
            }
            if (v[idx[m]] + v[idx[r]] == target) {
                cout << idx[l] + 1 << ' ' << idx[m] + 1 << ' ' << idx[r] + 1 << '\n';
                found = true;
            }
        }
    }
    
    if (!found) cout << "IMPOSSIBLE\n";
    
    return 0;
}