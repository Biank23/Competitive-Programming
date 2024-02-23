#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, target;
    cin >> n >> target;
    map<int, int> idx;
    bool found = false;
    for (int i = 1; i <= n && !found; i++) {
        int a;
        cin >> a;
        if (idx.count(target - a)) {
            cout << idx[target - a] << ' ' << i << '\n';
            found = true;
        }
        idx[a] = i;
    }
    if (!found) {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}
