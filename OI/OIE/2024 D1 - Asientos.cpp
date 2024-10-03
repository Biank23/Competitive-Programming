#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

#define sz(x) int(x.size())

using ll = long long;
template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const int MAX_A = 1e7 + 9;
int d[MAX_A];

void sieve() {
    memset(d, -1, sizeof d);
    for (int i = 2; i * i < MAX_A; i++) {
        if (d[i] != -1) continue;
        for (int j = i * i; j < MAX_A; j += i) {
            if (d[j] == -1) d[j] = i;
        }
    }
    for (int i = 0; i < MAX_A; i++) {
        if (d[i] == -1) d[i] = i;
    }
}

vector<ll> factors(ll n) {
    vector<ll> f;
    auto nxt = [](ll &x, ll p) {
        while (x % p == 0) x /= p;
    };
    if (n < MAX_A) {
        for (ll p; n > 1; nxt(n, p)) {
            f.push_back(p = d[n]);
        }
    } else {
        for (ll p = 2; p * p <= n; nxt(n, p++)) {
            if (n % p == 0) f.push_back(p);
        }
        if (n > 1) f.push_back(n);
    }
    return f;
}

inline ll remtz(ll x) {
    return x >> __builtin_ctzll(x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    sieve();
    int n;
    cin >> n;
    vector<ll> a;
    pair<ll, ll> best = {0, 2};
    auto &[mini, ans] = best;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x > 1) {
            a.push_back(x);
            mini += x % 2;
        }
    }
    n = sz(a);
    if (n == 0) {
        cout << "2\n";
        return 0;
    }
    set<ll> done{2};
    indexed_set<ll> s;
    for (int i = 0; i < n; i++) {
        s.insert(remtz(a[i])), s.insert(remtz(a[i] - 1));
    }
    while (!s.empty() && clock() / (double) CLOCKS_PER_SEC < 3.8) {
        auto it = s.find_by_order(uniform_int_distribution<int>(0, sz(s) - 1)(rng));
        for (ll m : factors(*it)) {
            if (done.count(m)) continue;
            done.insert(m);
            ll curr = 0;
            for (int i = 0; i < n; i++) {
                curr += a[i] % m;
                if (curr > mini) break;
            }
            best = min(best, {curr, m});
        }
        s.erase(it);
    }
    cout << ans << '\n';
    
    return 0;
}