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
 
const int MAX_N = 2e5 + 9;
 
ll memo[MAX_N];
vector<Project> p;
 
ll dp(int i) {
    if (i < 0) return 0;
    ll &res = memo[i];
    if (res != -1) return res;
    int j = int(upper_bound(all(p), Project{0, p[i].start}) - begin(p));
    return res = max(dp(i - 1), dp(j - 1) + p[i].reward);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].start >> p[i].end >> p[i].reward;
    }
    memset(memo, -1, sizeof memo);
    sort(all(p));
    cout << dp(n - 1) << '\n';
    
    return 0;
}