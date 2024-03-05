#include <bits/stdc++.h>
 
using namespace std;

using ll = long long;

const int MAX_K = 30;

struct Node {
    int mini[MAX_K];
    ll sum[MAX_K];
    Node() {
        int nextPow = 2;
        for (int i = 0; i < MAX_K; i++) {
            mini[i] = nextPow;
            sum[i] = 0;
            nextPow *= 2;
        }
    }
    Node(int x) : Node() {
        int log = 31 - __builtin_clz(x);
        mini[log] = x, sum[log] = x;
    }
};

Node op(const Node &a, const Node &b) {
    Node c;
    for (int i = 0; i < MAX_K; i++) {
        c.mini[i] = min(a.mini[i], b.mini[i]);
        c.sum[i] = a.sum[i] + b.sum[i];
    }
    return c;
}
 
const int MAX_N = 2e5;
 
Node st[2 * MAX_N];
int n;
 
void init(vector<int> &v) {
    for (int i = 0; i < n; i++) {
        st[i + n] = v[i];
    }
	for (int i = n - 1; i > 0; i--) {
        st[i] = op(st[2 * i], st[2 * i + 1]);
    }
}
 
Node query(int l, int r) { //[l, r)
    Node res;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) res = op(res, st[l++]);
        if (r & 1) res = op(st[--r], res);
    }
    return res;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int q;
    cin >> n >> q;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    init(x);

    while (q--) {
        int l, r;
        cin >> l >> r;
        Node range = query(l - 1, r);
        ll smallestMissingSum = 1;
        for (int i = 0; i < MAX_K && range.mini[i] <= smallestMissingSum; i++) {
            smallestMissingSum += range.sum[i];
        }
        cout << smallestMissingSum << '\n';
    }
	
	return 0;
}