#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) (int)(x.size())
#define all(x) begin(x), end(x)
 
using ll = long long;
 
const ll MOD = 3006703054056749;
const int ALPHA = 4;
 
const map<char, int> pos = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
 
void add(ll &x, ll v) {
    if ((x += v) >= MOD) x -= MOD;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1e9);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<ll> val(n);
    ll tot = 0LL;
    vector<vector<ll>> sum(m, vector<ll>(ALPHA, 0LL));
    for (int i = 0; i < n; i++) {
        val[i] = dist(gen);
        add(tot, val[i]);
        for (int j = 0; j < m; j++) {
            add(sum[j][pos.at(s[i][j])], val[i]);
        }
    }
    ll target = k * tot % MOD;
    for (int i = 0; i < n; i++) {
        ll curr = k * val[i] % MOD;
        for (int j = 0; j < m; j++) {
            ll diff = tot - sum[j][pos.at(s[i][j])];
            if (diff < 0) diff += MOD;
            add(curr, diff);
        }
        if (curr == target) {
            cout << i + 1 << '\n';
        }
    }
    
    return 0;
}