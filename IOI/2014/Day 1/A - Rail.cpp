#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ii = pair<int, int>;
#define fst first
#define snd second

const int C = 0, D = 1;

int getDistance(int i, int j);

void findLocation(int n, int first, int loc[], int stype[]) {
    vector<ii> p(n);
    for (int i = 1; i < n; i++) {
        p[i] = {getDistance(0, i), i};
    }
    sort(all(p));
    set<ii> s[2];
    auto add = [&](int i, int type) {
        stype[i] = type + 1;
        s[type].emplace(loc[i], i);
    };
    for (auto [d0, i] : p) {
        if (s[C].empty()) {
            loc[i] = first;
            add(i, C);
            continue;
        }
        int minC = s[C].begin()->snd;
        if (s[D].empty()) {
            loc[i] = loc[minC] + d0;
            add(i, D);
            continue;
        }
        int maxD = s[D].rbegin()->snd;
        int distIto[2] = {getDistance(i, minC), getDistance(maxD, i)};
        
        loc[i] = loc[minC] + distIto[C];
        int target = (loc[i] + loc[maxD] - distIto[D])/2;
        auto it = s[C].lower_bound(ii{target, 0});
        if (it != end(s[C]) && loc[i] + loc[maxD] - 2 * it->fst == distIto[D]) {
            add(i, D);
            continue;
        }
        
        loc[i] = loc[maxD] - distIto[D];
        target = (distIto[C] + loc[i] + loc[minC])/2;
        it = s[D].lower_bound(ii{target, 0});
        if(it != end(s[D]) && 2 * it->fst - loc[i]- loc[minC] == distIto[C]) {
            add(i, C);
            continue;
        }
        
        loc[i] = loc[minC] + distIto[C];
        if(d0 == loc[i] - first) {
            add(i, D);
        } else {
            loc[i] = loc[maxD] - distIto[D];
            add(i, C);
        }
    }
}
