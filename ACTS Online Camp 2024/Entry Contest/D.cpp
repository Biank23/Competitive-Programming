#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

struct Data {
    ll duration, hat, time, id;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    deque<Data> dq;
    ll time = 0;
    for (int i = 1; i <= n; i++) {
        ll h, s, t;
        cin >> h >> s >> t;
        while (!dq.empty() && time < s) {
            cout << dq.front().id << ' ';
            time = max(time, dq.front().time);
            time += dq.front().duration;
            dq.pop_front();
        }
        if (sz(dq) >= 2 && end(dq)[-1].hat == end(dq)[-2].hat && end(dq)[-1].hat != h) {
            ll p = end(dq)[-1].hat;
            while (!dq.empty() && dq.back().hat == p) dq.pop_back();
        }
        dq.push_back({t, h, s, i});
    }
    while (!dq.empty()) {
        cout << dq.front().id << ' ';
        dq.pop_front();
    }

    return 0;
}
