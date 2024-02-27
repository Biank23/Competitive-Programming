#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1e18;
 
struct Node {
	ll sum, prefix, suffix, best;
    Node() : sum(0) {
        prefix = suffix = best = -INF;
    }
	Node(ll v) : sum(v) {
		prefix = suffix = best = max(0LL, v);
	}
	friend Node op(const Node &a, const Node &b) {
        Node c;
        c.sum = a.sum + b.sum;
        c.prefix = max(a.prefix, a.sum + b.prefix);
        c.suffix = max(a.suffix + b.sum, b.suffix);
        c.best = max({a.best, b.best, a.suffix + b.prefix});
        return c;
	}
};
 
const int SZ = 1<<18;
 
Node st[2 * SZ];
 
void update(int i, int v) {
	for (st[i += SZ] = v; i /= 2;) {
        st[i] = op(st[2 * i], st[2 * i + 1]);
    }
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	for (int i = 0; i < n; i++) {
        int v;
		cin >> v;
		st[i + SZ] = v;
	}
	for (int i = SZ - 1; i > 0; i--) {
		st[i] = op(st[2 * i], st[2 * i + 1]);
	}
	
	while (q--) {
		int k, x;
		cin >> k >> x;
        update(k - 1, x);
        cout << st[1].best << '\n';
	}
}