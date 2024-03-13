#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;
using ll = long long;

vi getDivisors(int x) {
    vi d;
    for (int i = 2; i <= 41; i++) {
        if (x % i == 0) d.push_back(i);
    }
    return d;
}

const int INF = 1e9;

pair<int, vi> dfs(vi &d, int P, int i = 0, int sum = 0, vi curr = {}) {
    if (sum > 41) return {INF, {}};
    if (P == 1) {
        while (sum < 41) {
            curr.push_back(1);
            sum++;
        }
        return {sz(curr), curr};
    }
    if (i >= sz(d)) return {INF, {}};
    auto ans = dfs(d, P, i + 1, sum, curr);
    while (P % d[i] == 0) {
        curr.push_back(d[i]);
        P /= d[i];
        sum += d[i];
        ans = min(ans, dfs(d, P, i + 1, sum, curr));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 1 ; tt <= TT; tt++) {
        cout << "Case #" << tt << ": ";
        int P;
        cin >> P;
        
        vi d = getDivisors(P);
        auto ans = dfs(d, P);
        if (ans.first > 100) {
            cout << "-1\n";
            continue;
        }
        
        cout << ans.first << ' ';
        for (int x : ans.second) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
