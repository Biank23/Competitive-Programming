#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, target;
    cin >> n >> target;
    vector<int> a(n), idx(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        idx[i] = i;
    }
    sort(all(idx), [&](const int &x, const int &y){
        return a[x] < a[y];
    });
    
    int r = n - 1;
    bool found = false;
    for (int l = 0; l < r && !found; l++) {
        int i = idx[l], j = idx[r];
        while (r - 1 > l && a[i] + a[j] > target) {
            j = idx[--r];
        }
        if (a[i] + a[j] == target) {
            cout << idx[l] + 1 << ' ' << idx[r] + 1 << '\n';
            found = true;
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}
