#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ll = long long;
 
struct Project {
    int start, end, reward;
};
 
bool operator<(const Project &a, const Project &b) {
    if (a.end != b.end) {
        return a.end < b.end;
    }
    return a.start < b.start;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<Project> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].start >> p[i].end >> p[i].reward;
    }
    sort(all(p));
    
    vector<ll> dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int j = int(upper_bound(all(p), Project{0, p[i].start}) - p.begin());
        dp[i + 1] = max(dp[i], dp[j] + p[i].reward);
    }
    cout << dp[n] << '\n';
    
    return 0;
}