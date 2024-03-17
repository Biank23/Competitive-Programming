#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Node {
    int remove, add;
    Node() : remove(INF), add(0) {}
};

const int SZ = 1<<21;
Node st[2 * SZ];

void maxi(int &x, int h) {
    if (h > x) x = h;
}
void mini(int &x, int h) {
    if (h < x) x = h;
}

void compute(int u, Node h) {
    mini(st[u].remove, h.remove);
    mini(st[u].add, st[u].remove);
    maxi(st[u].add, h.add);
    maxi(st[u].remove, st[u].add);
}
    
void pass(int u) {
    if (u < SZ) {
        compute(2 * u, st[u]);
        compute(2 * u + 1, st[u]);
        st[u] = Node();
    }
}

void update(int a, int b, Node h, int l = 0, int r = SZ, int u = 1) {
    pass(u);
    if (b <= l || r <= a) {
        return;
    }
    if (a <= l && r <= b) {
        return compute(u, h);
    }
    int m = (l + r) / 2;
    update(a, b, h, l, m, 2 * u);
    update(a, b, h, m, r, 2 * u + 1);
}

void dfs(int ans[], int n, int l = 0, int r = SZ, int u = 1) {
    pass(u);
    if (r - l == 1) {
        if (l < n) {
            ans[l] = st[u].add;
        }
        return;
    }
    int m = (l + r) / 2;
    dfs(ans, n, l, m, 2 * u);
    dfs(ans, n, m, r, 2 * u + 1);
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
    for (int i = 0; i < k; i++) {
        Node h;
        if (op[i] == 1) {
            h.add = height[i];
        } else {
            h.remove = height[i];
        }
        update(left[i], right[i] + 1, h);
    }
    dfs(finalHeight, n);
}
