#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
using ll = long long;
 
const int MAX_N = 2e6+5;
const int DIFF = 1e6+1;
 
int ft[MAX_N];
 
inline int lsb(int i) {
    return i & (-i);
}
 
void update(int i, int v) {
    while (i < MAX_N) {
        ft[i] += v;
        i += lsb(i);
    }
}
 
int query(int i) {
    int s = 0;
    while (i > 0) {
        s += ft[i];
        i -= lsb(i);
    }
    return s;
}
 
const int INSERT = 1;
const int EVAL = 0;
const int ERASE = -1;
 
struct Event {
    int type, x, y1, y2;
    bool operator<(const Event &o) {
        if (x != o.x) return x < o.x;
        return type < o.type;
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<Event> events;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1 += DIFF, y2 += DIFF;
        if(x1 == x2) {
            events.emplace_back(EVAL, x1, y1, y2);
        } else {
            events.emplace_back(INSERT, x1, y1, y2);
            events.emplace_back(ERASE, x2, y1, y2);
        }
    }
    
    sort(all(events));
    ll ans = 0;
    for (auto [type, x, y1, y2] : events) {
        if (type == EVAL) {
            ans += query(y2) - query(y1);
        } else if (type == INSERT) {
            update(y1, 1);
        } else if (type == ERASE) {
            update(y1, -1);
        } else {
            assert(false);
        }
    }
    cout << ans << '\n';
    
    return 0;
}