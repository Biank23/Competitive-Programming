#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 9;
const int INF = 1e9;

int st[2 * MAXN], n;

void init() {
    for (int i = 0; i < 2 * MAXN; i++) {
        st[i] = INF;
    }
}

void update(int p, int v){
    p += n;
    if (v < st[p]) {
        st[p] = v;
        while (p /= 2) st[p] = min(st[2 * p], st[2 * p + 1]);
    }
}

int query(int l, int r) {
    int ans = INF;
    for(l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) ans = min(ans, st[l++]);
        if (r & 1) ans = min(st[--r], ans);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    init();
    int m;
    cin >> n >> m;
    update(0, 0);
    while (m--) {
        int s,e;
        cin >> s >> e;
        --s, --e;
        update(e, query(s, e) + 1);
    }
    cout << query(n - 1, n) << '\n';
    

    return 0;
}