#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;

struct Problem {
    ll p, f, t;
    bool operator<(const Problem &o) {
        return t * o.f < o.t * f;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, T;
    cin >> N >> T;
    vector<Problem> v(N);
    for (auto &[p, f, t] : v) {
        cin >> p >> f >> t;
    }
    sort(all(v));
    vector<ll> dp(T + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int j = T; j >= v[i].t; j--) {
            dp[j] = max(dp[j], dp[j - v[i].t] + max(0LL, v[i].p - j * v[i].f));
        }
    }
    cout << *max_element(all(dp)) << '\n';
    
    return 0;
}