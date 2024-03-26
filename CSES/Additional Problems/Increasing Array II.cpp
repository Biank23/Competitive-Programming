#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    priority_queue<int> S;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        S.push(x[i]);
        ans += S.top() - x[i];
        S.pop();
        S.push(x[i]);
    }
    cout << ans << '\n';
    
    return 0;
}
