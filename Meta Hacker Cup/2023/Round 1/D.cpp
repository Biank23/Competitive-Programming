#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;
using ii = pair<ll, ll>;

const int MOD = 1e9 + 7;
const ll INF = 1e9 + 30;

struct Node {
	ii val[2];
	bool lazy = false;
	Node() {
		val[0] = val[1] = {-INF, 1};
	}
	Node(ll x, ll p) {
		val[0] = {x, -p};
        val[1] = {x * (MOD - 1) % MOD, -p};
	}
	friend Node op(Node a, Node b) {
        Node c;
        for (int i = 0; i < 2; i++) {
            c.val[i] = max(a.val[i], b.val[i]);
        }
        return c;
	}
};

struct STree {
	vector<Node> st;
	int n = 1;
	STree(vector<int> &v) {
        while (n < sz(v)) {
            n *= 2;
        }
        st.resize(2 * n);
        for (int i = 0; i < sz(v); i++) {
            st[i + n] = Node(v[i], i + 1);
        }
		for (int i = n - 1; i >= 0; i--) {
            st[i] = op(st[2 * i], st[2 * i + 1]);
        }
	}
	void pass(int u) {
        if (u < n) {
            st[2 * u + 1].lazy ^= st[u].lazy;
            st[2 * u].lazy ^= st[u].lazy;
		}
		if (st[u].lazy) {
			swap(st[u].val[0], st[u].val[1]);
		}
		st[u].lazy = false;
	}
	void update(int s, int e, int l, int r, int u) {
        pass(u);
        if (e <= l || r <= s) return;
        if (s <= l && r <= e) {
            st[u].lazy = true;
            return pass(u);
        }
        int m = (l + r) / 2;
        update(s, e, l, m, 2 * u);
        update(s, e, m, r, 2 * u + 1);
        st[u] = op(st[2 * u], st[2 * u + 1]);
    }
    void update(int s, int e) {
        return update(s, e, 0, n, 1);
    }
    ll query() {
        return -st[1].val[0].second;
    }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int TT;
	cin >> TT;
	for (int tt = 1 ; tt <= TT; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        STree st(a);
        int q;
        cin >> q;
        ll ans = 0;
        while (q--) {
            int l, r;
            cin >> l >> r;
            st.update(l - 1, r);
            ans += st.query();
        }
        cout << "Case #" << tt << ": " << ans << '\n';
    }
    
    return 0;
}
