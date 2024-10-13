#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) int(x.size())

using ll = long long;
using ii = pair<int, int>;

const int N = 40000;
const int LIMIT = 1000000000;

int n;
bool testing = false;
int q = 0;

bool query(int a, int b) {
    q++;
    if (testing) {
        assert(q <= 60);
        ll val = 1 % b;
        for (int i = 1; i <= n; i++) {
            val *= i;
            val %= b;
        }
        val += a;
        val %= b;
        return val == 0;
    }
    cout << "? " << a << ' ' << b << endl;
    string ans;
    cin >> ans;
    assert(ans != "ERROR");
    return ans == "SI";
}

bool query(int x) { return query(x, x); }

vector<int> get_primes() {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 4; i <= N; i += 2) is_prime[i] = false;
    for (int i = 3; i * i <= N; i += 2) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= N; j += i) is_prime[j] = false;
    }
    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}

ll v(int p, int n) { //valor p-ádico de n!
    ll d = p, val = 0;
    while (n / d) {
        val += n / d;
        d *= p;
    }
    return val;
}

int search(int p, int k) { //primer n tal que v_p(n!) >= k
    int lo = 0, hi = N + 1;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (v(p, mid) >= k) hi = mid;
        else lo = mid;
    }
    return hi;
}

vector<ii> get_candidates() {
    vector<ii> candidates;
    for (int p : get_primes()) {
        int k = 1;
        ll num = p;
        while (num <= LIMIT) {
            int minimum = search(p, k);
            if (minimum == N + 1) break;
            candidates.emplace_back(minimum, num);
            num *= p, k++;
        }
    }
    sort(all(candidates));
    candidates.erase(unique(all(candidates), [](const ii &lhs, const ii &rhs) { return lhs.first == rhs.first; }), end(candidates));
    return candidates;
}

const int P = 998244353;

vector<int> get_factorials() {
    vector<int> fact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = 1LL * fact[i - 1] * i % P;
    return fact;
}

void check_range(int lo, int hi) {
    vector<int> fact = get_factorials();
    for (int i = lo; i < hi; i++) {
        if (query(P - fact[i], P)) {
            cout << "! " << i << endl;
            exit(0);
        }
    }
    assert(false);
}

int main() {
    if (testing) cin >> n;
    vector<ii> candidates = get_candidates();
    auto get_range = [&](int hi) {
        return ii{hi > 0 ? candidates[hi - 1].first : 1, hi < sz(candidates) ? candidates[hi].first : N + 1};
    };
    q = 0;
    int lo = -1, hi = sz(candidates);
    vector<int> p(sz(candidates) + 1);
    iota(all(p), 0);
    sort(all(p), [&](const int &lhs, const int &rhs) {
        auto [lhs_l, lhs_r] = get_range(lhs);
        auto [rhs_l, rhs_r] = get_range(rhs);
        return lhs_r - lhs_l > rhs_r - rhs_l;
    });
    for (int i : p) {
        auto [l, r] = get_range(i);
        if (r - l + ceil(log2(hi - lo)) + q > 60) {
            if (lo > i - 1) continue;
            if (hi < i) continue;
            if (lo != i - 1) {
                if (query(candidates[i - 1].second)) lo = i - 1;
                else {
                    hi = i - 1;
                    continue;
                }
            }
            if (hi != i) {
                if (!query(candidates[i].second)) hi = i;
                else {
                    lo = i;
                    continue;
                }
            }
            check_range(l, r);
        }
    }
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (query(candidates[mid].second)) lo = mid;
        else hi = mid;
    }
    auto [l, r] = get_range(hi);
    check_range(l, r);
    
    
    return 0;
}
