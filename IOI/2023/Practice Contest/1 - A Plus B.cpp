#include <bits/stdc++.h>
#include "aplusb.h"

using namespace std;

#define sz(x) int(x.size())

using ii = pair<int, int>;
using vi = vector<int>;

vi smallest_sums(int n, vi a, vi b) {
    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
    set<ii> vis;
    auto push = [&](int i, int j) {
        pq.emplace(a[i] + b[j], ii{i, j});
        vis.emplace(i, j);
    };
    push(0, 0);
    vi ans;
    while (sz(ans) < n) {
        auto [sum, pos] = pq.top();
        ans.push_back(sum);
        pq.pop();
        auto [i, j] = pos;
        if (i + 1 < n && !vis.count({i + 1, j})) {
            push(i + 1, j);
        }
        if (j + 1 < n && !vis.count({i, j + 1})) {
            push(i, j + 1);
        }
    }
    return ans;
}
