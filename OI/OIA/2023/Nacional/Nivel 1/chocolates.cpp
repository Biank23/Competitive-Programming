#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;

int chocolates(int K, vi &x) {
    priority_queue<int> pq;
    for (int i = 0; i < sz(x); i++) {
        pq.push(x[i]);
    }
    int c = 0;
    while (!pq.empty()) {
        vi v(K);
        bool flag = true;
        for (int i = 0; i < K && flag; i++) {
            if (pq.empty()) {
                flag = false;
            } else {
                v[i] = pq.top();
                pq.pop();
            }
        }
        if (!flag) {
            break;
        }
        int sig = pq.empty() ? 0 : pq.top();
        int t = max(1, v.back() - sig);
        for (int i = 0; i < K; i++) {
            if (v[i] - t > 0) pq.push(v[i] - t);
        }
        c += t;
    }
    return c;
}
