#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

typedef long long ll;

const int MAX_N = 2e5 + 20;

int ft[MAX_N];

inline int lsb(int i) {
    return i & (-i);
}

void update(int i) {
    i++;
    while (i < MAX_N) {
        ft[i]++;
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

ll count_swaps(vector<int> S) {
    int n = sz(S);
    
    vector<pair<int, int>> pairs;
    map<int, queue<int>> m;
    
    for (int i = 0; i < n; i++) {
        if (!m[S[i]].empty()) {
            pairs.emplace_back(m[S[i]].front(), i);
            m[S[i]].pop();
        } else {
            m[-S[i]].push(i);
        }
    }
    
    ll ans = 0;
    for (auto [x, y] : pairs) {
        if (S[y] < S[x]) {
            swap(x, y);
        }
        for (int p : {x, y}) {
            ans += p - query(p);
            update(p);
        }
    }
    return ans;
}
