#pragma once
#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

struct STree {
    struct Node {
        int cant;
        ll sum;
        Node() : cant(0), sum(0LL) {}
        Node(int val) : cant(1), sum(val) {}
        friend Node operator+(Node lhs, Node rhs) {
            Node res;
            res.cant = lhs.cant + rhs.cant;
            res.sum = lhs.sum + rhs.sum;
            return res;
        }
    };
    int n;
    vector<Node> st;
    vector<int> a, positions;
    STree(int S) {
        n = 1;
        while (n < S) n *= 2;
        st.assign(2 * n, Node());
    }
    void activate(int i) {
        int pos = positions[i] + n;
        st[pos] = a[i];
        while (pos /= 2) {
            st[pos] = st[2 * pos] + st[2 * pos + 1];
        }
    }
    void deactivate(int i) {
        int pos = positions[i] + n;
        st[pos] = Node();
        while (pos /= 2) {
            st[pos] = st[2 * pos] + st[2 * pos + 1];
        }
    }
    ll query(int x) {
        int u = 1;
        ll res = 0;
        while (u < n) {
            u *= 2;
            if (st[u].cant <= x) {
                x -= st[u].cant;
                res += st[u].sum;
                u++;
            }
        }
        if (st[u].cant <= x) res += st[u].sum;
        return res;
    }
};

void rec(int dLow, int dHigh, int rLow, int rHigh, STree &st, vector<pair<ll, int>> &ans, int cost) {
    if (dLow > dHigh) return;
    int d = (dLow + dHigh) / 2;
    ans[d] = {-1, 1};
    for (int i = rLow; i <= rHigh; i++) {
        st.activate(i);
        ans[d] = max(ans[d], {st.query(d - cost * i), -i});
    }
    int rOpt = -ans[d].second;
    for (int i = rHigh; i >= rOpt; i--) {
        st.deactivate(i);
    }
    rec(d + 1, dHigh, rOpt, rHigh, st, ans, cost);
    for (int i = rOpt - 1; i >= rLow; i--) {
        st.deactivate(i);
    }
    rec(dLow, d - 1, rLow, rOpt, st, ans, cost);
}

vector<ll> solve(vector<int> a, int cost, int D) {
    int n = sz(a);
    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](int x, int y) {
        return a[x] > a[y];
    });
    vector<int> positions(n);
    for (int i = 0; i < n; i++) {
        positions[order[i]] = i; 
    }
    STree st(n);
    st.a = a, st.positions = positions;
    vector<pair<ll, int>> ans(D + 1);
    rec(0, D, 0, n - 1, st, ans, cost);
    vector<ll> best(D + 1);
    for (int i = 0; i <= D; i++) {
        best[i] = ans[i].first;
        if (i > 0) best[i] = max(best[i], best[i - 1]);
    }
    return best;
}

ll findMaxAttraction(int n, int start, int d, int attraction[]) {
    vector<int> left, right;
    for (int i = 0; i < start; i++) left.push_back(attraction[i]);
    for (int i = start; i < n; i++) right.push_back(attraction[i]);
    left.push_back(0);
    reverse(all(left));
    vector<ll> max_left[2], max_right[2];
    for (int i = 0; i < 2; i++) {
        max_left[i] = solve(left, i + 1, d);
        max_right[i] = solve(right, i + 1, d);
    }
    ll best = 0LL;
    for (int i = 0; i <= d; i++) {
        best = max({best, max_left[0][i] + max_right[1][d - i], max_left[1][i] + max_right[0][d - i]});
    }
    return best;
}
