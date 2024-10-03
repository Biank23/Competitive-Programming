#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x),end(x)
#define forn(i,n) for(int i=0;i<int(n);i++)
#define dbg(x) cerr<<#x<<": "<<x<<endl

#define fst first
#define snd second
#define pb push_back

typedef long long ll;
typedef pair<ll,ll> ii;

const int MOD = 1e9+7;

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

int binpow(int a, ll k) {
    int res = 1;
    while (k > 0) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a), k /= 2;
    }
    return res;
}

struct Range {
    ll l, r;
    int id;
    bool operator<(const Range &o) const {
        return l < o.l;
    }
};

vector<int> par, state;
set<Range> s;
ll n, sum = 0;
int cmp = 0;
bool possible = true;

int find(int x) {
    if (par[x] != x) par[x] = find(par[x]);
    return par[x];
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    par[x] = y;
    if (state[x] == -1 || state[y] == -1) cmp--;
    if (state[y] == -1) {
        state[y] = state[x];
    } else if (state[x] != -1 && state[y] != state[x]) {
        possible = false;
    }
}

int getAns() {
    if (!possible) return 0;
    return binpow(62, (n + 1) / 2 - sum + cmp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m;
    cin >> n >> m;
    auto normalize = [&](ll &x) {
        if (--x >= (n + 1) / 2) x = n - 1 - x;
    };
    auto getRange = [&](ll x) {
        auto it = s.upper_bound(Range{x, 0, 0});
        if (it == s.begin() || (--it)->r < x) {
            it = s.insert(Range{x, x, sz(par)}).fst;
            sum++, cmp++;
            par.pb(sz(par)), state.pb(-1);
        }
        return it;
    };
    auto val = [](char c){
        if ('a' <= c && c <= 'z') return c - 'a';
        if ('A' <= c && c <= 'Z') return c - 'A' + 26;
        return c - '0' + 52;
    };
    while (m--) {
        cout << getAns() << '\n';
        int t; cin >> t;
        if (t == 1) {
            ll x; 
            char c;
            cin>>x>>c;
            normalize(x);
            int parent = find(getRange(x)->id);
            if (state[parent] == -1) {
                state[parent] = val(c);
                cmp--;
            } else if (state[parent] != val(c)) {
                possible = false;
            }
        } else if (t == 2) {
            ll x, y;
            cin >> x >> y;
            normalize(x), normalize(y);
            unite(getRange(x)->id, getRange(y)->id);
        } else if (t == 3) {
            ll l, r;
            cin >> l >> r;
            if (l <= (n + 1) / 2 && (n + 1) / 2 < r){
                normalize(l), normalize(r);
                l = min(l, r), r = (n + 1) / 2 - 1;
            } else {
                normalize(l), normalize(r);
                if (l > r) swap(l, r);
            }
            auto it = getRange(l);
            ll left = it->l, right = getRange(r)->r;
            int id = it->id;
            while (it != s.end() && it->r <= right) {
                unite(id, it->id);
                sum -= it->r - it->l + 1;
                it = s.erase(it);
            }
            sum += right - left + 1;
            s.insert(Range{left, right, id});
        } else {
            assert(false);
        }
    }
    cout << getAns() << '\n';
    
    return 0;
}