#include <bits/stdc++.h>
 
using namespace std;
 
struct Range {
    int l, r, idx;
};
 
#define all(x) begin(x), end(x)
 
const int MAX_N = 2e5 + 9;
const int INF = 1e9 + 20;
 
bitset<MAX_N> ans;
 
void print(int n) {
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<Range> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r;
        v[i].idx = i;
    }
    sort(all(v), [](const Range &lhs, const Range &rhs){
        if (lhs.l != rhs.l) return lhs.l > rhs.l;
        return lhs.r < rhs.r;
    });
    
    int minR = INF;
    for (int i = 0; i < n; i++) {
        ans[v[i].idx] = minR <= v[i].r;
        minR = min(minR, v[i].r);
    }
    print(n);
    
    int maxR = -INF;
    for (int i = n - 1; i >= 0; i--) {
        ans[v[i].idx] = maxR >= v[i].r;
        maxR = max(maxR, v[i].r);
    }
    print(n);
    
    return 0;
}