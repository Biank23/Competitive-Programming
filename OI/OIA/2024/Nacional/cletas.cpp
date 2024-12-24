#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

ll cletas(vector<int> &x, vector<int> &c) {
    int n = sz(x);
    ll T = 0LL;
    for (int i = 0; i < n; i++) T += c[i];
    ll cant = T / n;
    vector<pair<int, int>> bici(n);
    for (int i = 0; i < n; i++) {
        bici[i] = {x[i], c[i] - cant};
    }
    sort(all(bici));
    ll pref = 0LL, res = 0LL;
    for (int i = 0; i < n - 1; i++) {
        int dist = bici[i + 1].first - bici[i].first;
        pref += bici[i].second;
        res += abs(pref) * dist;
    }
    return res;
}
