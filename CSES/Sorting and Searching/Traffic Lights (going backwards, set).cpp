#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int x, n;
    cin >> x >> n;
 
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    set<int> lights{0, x};
    lights.insert(all(p));
    
    int prevPos = 0, maxDist = 0;
    for (int currPos : lights) {
        maxDist = max(maxDist, currPos - prevPos);
        prevPos = currPos;
    }
    
    vector<int> res(n);
    res[n - 1] = maxDist;
    
    for (int i = n - 1; i >= 1; i--) {
        lights.erase(p[i]);
        auto it = lights.upper_bound(p[i]);
        res[i - 1] = max(res[i], *it - *prev(it));
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}