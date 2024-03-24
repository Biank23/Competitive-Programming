#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;

char query(ll y){
    cout << "? " << y << endl;
    char ans;
    cin >> ans;
    if (ans == '=') {
        exit(0);
    }
    return ans;
}

int main() {    
    ll n, q;
    cin >> n >> q;
    vector<vll> dp(q, vll(8, 0));
    for (int i = 1; i < 7; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < q; i++) {
        for (int j = 0; j < 7; j++) {
            dp[i][j] = dp[i - 1][j + 1] + 1 + dp[i - 1][1];
        }
    }
    int consecutive = 0;
    char prevAns = '-';
    ll l = 1, r = n;
    while (--q) {
        ll length = dp[q - 1][consecutive + 1];
        ll m = prevAns == '<' ? min(l + length, r) : max(r - length, l);
        char ans = query(m);
        if (ans == '<') {
            r = m - 1;
        } else {
            l = m + 1;
        }
        if (ans != prevAns) {
            consecutive = 0;
        }
        consecutive++;
        prevAns = ans;
    }
    query(l);
    
    return 0;
}
