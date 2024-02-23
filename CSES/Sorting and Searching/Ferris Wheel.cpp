#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(all(p));
    int l = 0, r = n - 1;
    int gondolas = 0;
    while (l <= r) {
        gondolas++;
        if (p[l] + p[r] <= x) {
            l++;
        }
        r--;
    }
    cout << gondolas << '\n';
    
    return 0;
}
