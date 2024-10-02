#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            --v[i][j];
        }
    }
    int upper = 0, lower = 0;
    #define sign(x) (x < 0 ? -1 : x > 0 ? 1 : 0)
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        upper += v[0][i];
        lower += v[1][i];
        if (sign(upper) * sign(lower) == -1) {
            if (abs(lower) < abs(upper)) {
                ans += abs(lower);
                upper += lower;
                lower = 0;
            } else {
                ans += abs(upper);
                lower += upper;
                upper = 0;
            }
        }
        ans += abs(upper) + abs(lower);
    }
    cout << ans << '\n';
    
    return 0;
}