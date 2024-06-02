#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_A = 1e7+9;

int d[MAX_A];
vector<int> primos;
vector<ll> valorRandom;

void criba() {
    int c = 0;
    for (int i = 2; i * i < MAX_A; i++) {
        if (d[i]) continue;
        c++;
        for (int j = i * i; j < MAX_A; j += i) {
            if (!d[j]) d[j] = c;
        }
    }
    c = 0;
    for (int i = 1; i < MAX_A; i++) {
        if (d[i]) continue;
        d[i] = c++;
        primos.push_back(i);
        valorRandom.push_back(uniform_int_distribution<ll>(1, 1e18)(rng));
    }
}

ll factorizar(int x) {
    ll h = 0;
    while (x != 1) {
        h ^= valorRandom[d[x]];
        x /= primos[d[x]];
    }
    return h;
}

ll perfectos(vector<int> &ronda) {
    int n = sz(ronda);
    criba();
    vector<ll> hashes(n);
    for (int i = 0; i < n; i++) {
        hashes[i] = factorizar(ronda[i]);
    }
    unordered_map<ll, int> m;
    ll suff = 0;
    for (int i = n - 1; i > 0; i--) {
        suff ^= hashes[i];
        m[suff]++;
    }
    ll pref = 0;
    ll ans = m[pref];
    for (int i = 1; i < n; i++) {
        m[suff]--;
        suff ^= hashes[i];
        m[pref]++;
        pref ^= hashes[i - 1];
        ans += m[pref];
    }
    pref ^= hashes.back();
    if (pref == 0) ans++;
    return ans;
}
