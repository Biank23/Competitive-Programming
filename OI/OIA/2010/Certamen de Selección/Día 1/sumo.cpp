#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int MAX_N = 1e5 + 9;

int ft[MAX_N];

void update(int i) {
    for (++i; i < MAX_N; i += i&-i) {
        ft[i]++;
    }
}

int query(int i) {
    int s = 0;
    for (++i; i > 0; i -= i&-i) {
        s += ft[i];
    }
    return s;
}

struct Luchador {
    int p, h, idx;
    bool operator<(const Luchador &o) {
        if (p != o.p) return p < o.p;
        return h < o.h;
    }
};

int main() {
    freopen("sumo.in", "r", stdin);
	freopen("sumo.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<Luchador> v(n);
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].p >> v[i].h;
        v[i].idx = i;
        vals[i] = v[i].h;
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    for (int i = 0; i < n; i++) {
        v[i].h = int(lower_bound(all(vals), v[i].h) - begin(vals));
    }
    sort(all(v));
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[v[i].idx] = query(v[i].h);
        update(v[i].h);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}
