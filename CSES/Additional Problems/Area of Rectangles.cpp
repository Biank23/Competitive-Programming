#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ll = long long;
 
struct Node {
    int mini, count;
    Node() : mini(0), count(1) {}
};
Node op(const Node &a, const Node &b) {
    if (a.mini < b.mini) return a;
    if (b.mini < a.mini) return b;
    Node c;
    c.mini = a.mini;
    c.count = a.count + b.count;
    return c;
}
 
const int SZ = 1<<21;
 
Node st[2 * SZ];
int lazy[2 * SZ];
 
void init() {
    for (int i = SZ - 1; i > 0; i--) {
        st[i] = op(st[2 * i], st[2 * i + 1]);
    }
}
 
void pass(int u) {
    if (u < SZ) {
        lazy[2 * u] += lazy[u];
        lazy[2 * u + 1] += lazy[u];
    }
    st[u].mini += lazy[u];
    lazy[u] = 0;
}
 
void update(int s, int e, int v, int l = 0, int r = SZ, int u = 1){
    pass(u);
    if (e <= l || r <= s) {
        return;
    }
    if (s <= l && r <= e) {
        lazy[u] = v;
        return pass(u);
    }
    int m = (l + r) / 2;
    update(s, e, v, l, m, 2 * u);
    update(s, e, v, m, r, 2 * u + 1);
    st[u] = op(st[2 * u], st[2 * u + 1]);
}
 
ll query() {
    if(st[1].mini > 0) return SZ;
    return SZ - st[1].count;
}
 
struct Event {
    int x, y1, y2, v;
    bool operator<(const Event &o){
        if (x != o.x) {
            return x < o.x;
        }
        return v < o.v;
    }
};
 
const int OFFSET = 1e6;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<Event> events;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1 += OFFSET, y2 += OFFSET;
        events.emplace_back(x1, y1, y2, 1);
        events.emplace_back(x2, y1, y2, -1);
    }
    sort(all(events));
    init();
    ll res = 0;
    for (int i = 0; i < ssize(events); i++) {
        if (i > 0) {
            res += query() * (events[i].x - events[i - 1].x);
        }
        update(events[i].y1, events[i].y2, events[i].v);
    }
    cout << res << '\n';
}