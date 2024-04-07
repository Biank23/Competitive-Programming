#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()

using ll = long long;
 
const int MAX_N = 6e4 + 9;
 
int ft[MAX_N];
 
void update(int i, int v) {
    for (i++; i < MAX_N; i += i&-i) {
        ft[i] += v;
    }
}
 
int query(int i) {
    int s = 0;
    for (i++; i > 0; i -= i&-i) {
        s += ft[i];
    }
    return s;
}
 
struct Event {
    int type, x, y1, y2;
};
 
int main() {
    freopen("autodromo.in", "r", stdin);
	freopen("autodromo.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    vector<Event> events;
    int r = 2;
    while (r--) {
        int n;
        cin >> n;
        vector<int> x(n + 1), y(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        x[n] = x[0], y[n] = y[0];
        for (int i = 0; i < n; i++) {
            int x1 = min(x[i], x[i + 1]), x2 = max(x[i], x[i + 1]);
            int y1 = min(y[i], y[i + 1]), y2 = max(y[i], y[i + 1]);
            if (x1 == x2) {
                events.push_back({0, x1, y1, y2});
            } else {
                events.push_back({1, x1, y1, y2});
                events.push_back({-1, x2, y1, y2});
            }
        }
    }
    
    sort(all(events), [](const Event &a, const Event &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.type < b.type;
    });
    ll ans = 0;
    for (Event e : events) {
        if (e.type == 0) {
            ans += query(e.y2 - 1) - query(e.y1);
        } else {
            update(e.y1, e.type);
        }
    }
    cout << ans << '\n';
    
    return 0;
}
