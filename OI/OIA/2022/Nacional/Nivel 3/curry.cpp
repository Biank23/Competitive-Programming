#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;
using ii = pair<int, int>;

const int ALPHA = 52;

struct Node {
    int child[ALPHA];
};

using vi = vector<int>;

const int MAX_SIZE = 6e5;
Node trie[MAX_SIZE];
int trieSize = 1;

inline int val(char c) {
    if (islower(c)) return c - 'a';
    return c - 'A' + 26; 
}

void insert(string &s, vi &id) {
    int u = 0;
    for (char &c : s) {
        id.push_back(u);
        int &v = trie[u].child[val(c)];
        if (!v) v = trieSize++;
        u = v;
    }
    id.push_back(u);
}

ll curry(vector<string> &palabras, vi &significados) {
    int n = sz(palabras);
    vector<vi> pref(n), suff(n);
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        insert(palabras[i], pref[i]);
        reverse(all(palabras[i]));
        insert(palabras[i], suff[i]);
        reverse(all(palabras[i]));
        reverse(all(suff[i]));
        maxLength = max(maxLength, sz(palabras[i])); 
    }
    vector<vector<ii>> v(maxLength);
    for (int i = 0; i < n; i++) {
        int s = sz(palabras[i]) - 1;
        v[s].emplace_back(significados[i], i);
    }
    ll ans = 0;
    for (int s = 0; s < maxLength; s++) {
        if (v[s].empty()) continue;
        sort(all(v[s]));
        map<ii, pair<int, ll>> m;
        for (int i = 0; i <= s; i++) {
            for (int j = 0; j < sz(v[s]); j++) {
                auto [val, idx] = v[s][j];
                ii id = {pref[idx][i], suff[idx][i + 1]};
                if (m.count(id)) {
                    auto [cant, sum] = m[id];
                    ans += cant * val - sum;
                }
                m[id].first++;
                m[id].second += val;
            }
        }
    }
    return ans;
}
