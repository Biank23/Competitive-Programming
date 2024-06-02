#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MAX_X = 10000000000001;
const int MAX_SIZE = 10000000;

struct Node {
    ll diff;
    bool parity;
    int left, right;
    Node() {
        diff = 0LL;
        parity = 0;
        left = right = 0;
    }
};

Node st[MAX_SIZE];
int currSize = 2;

void update(ll x, ll l = 0, ll r = MAX_X, int u = 1) {
    if (r - l == 1) {
        st[u].diff ^= x;
        st[u].parity ^= 1;
        return;
    }
    ll m = (l + r) / 2;
    if (x < m) {
        if (st[u].left == 0) st[u].left = currSize++;
        update(x, l, m, st[u].left);
    } else {
        if (st[u].right == 0) st[u].right = currSize++;
        update(x, m, r, st[u].right);
    }
    st[u].parity = st[st[u].left].parity ^ st[st[u].right].parity;
    if (st[st[u].right].parity) {
        st[u].diff = -st[st[u].left].diff + st[st[u].right].diff;
    } else {
        st[u].diff = st[st[u].left].diff + st[st[u].right].diff;
    }
}

ll sum = 0;

ll agregar(ll x) {
    sum += x;
    update(x);
    return (sum + st[1].diff) / 2;
}

ll sacar(ll x) {
    sum -= x;
    update(x);
    return (sum + st[1].diff) / 2;
}
