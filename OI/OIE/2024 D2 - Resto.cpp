#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

const int MAX_N = 1e5;
const ll INF = 1e18;

ll st[2 * MAX_N];
int n;

void init(vector<ll> &a) {
    for (int i = 0; i < n; i++) {
        st[i + n] = a[i]; 
    }
    for (int i = n - 1; i > 0; i--) {
        st[i] = min(st[2 * i], st[2 * i + 1]);
    }
}

void update(int p, ll v) {
    for (st[p += n] = v; p /= 2;) {
        st[p] = min(st[2 * p], st[2 * p + 1]);
    }
}

vector<int> query(int l, int r) {
    vector<int> nodesL, nodesR;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) nodesL.push_back(l++);
        if (r & 1) nodesR.push_back(--r);
    }
    vector<int> nodes(all(nodesL));
    reverse(all(nodesR));
    for (int u : nodesR) nodes.push_back(u);
    return nodes;
}

int search(int u, ll val) {
    while (u < n) {
        u *= 2;
        if (st[u] > val) u++;
    }
    return u - n;
}

int find(int p, ll val) {
    vector<int> nodes = query(p, n);
    for (int u : nodes) {
        if (st[u] <= val) return search(u, val);
    }
    return n;
};

ll query(ll val) {
    int p = 0;
    ll ans = 0;
    while (p < n) {
        int nextP = find(p, val);
        ans += (nextP - p) * val;
        p = nextP;
        if (p != n) val %= st[p + n];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int q;
        cin >> n >> q;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        init(a);
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                ll x;
                cin >> x;
                cout << query(x) << '\n';
            } else {
                int p;
                ll v;
                cin >> p >> v;
                update(p - 1, v);
            }
        }
    }
    
    return 0;
}
