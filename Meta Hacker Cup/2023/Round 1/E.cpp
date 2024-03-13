#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

const int ALPHA = 26;

struct trieNode {
    int child[ALPHA];
    trieNode() {
        memset(child, 0, sizeof child);
    }
};

struct Trie {
    vector<trieNode> trie;
    Trie() {
        trie.reserve(1e7);
        trie.push_back(trieNode());
    }
    vector<int> insert(string &s) {
        int u = 0;
        vector<int> ids{u};
        for (char &c : s) {
            int &v = trie[u].child[c - 'a'];
            if (!v) {
                v = sz(trie);
                trie.push_back(trieNode());
            }
            u = v;
            ids.push_back(u);
        }
        return ids;
    }
    int size() {
        return sz(trie);
    }
    void clear() {
        trie.resize(1);
        trie[0] = trieNode();
    }
};

const int BLOCK_SIZE = 775;

struct Query {
    int l, r;
    bool operator<(const Query &o) {
        if (l / BLOCK_SIZE != o.l / BLOCK_SIZE)
            return l < o.l;
        if (l / BLOCK_SIZE & 1)
            return r < o.r;
        return r > o.r;
    }
};

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    Trie trie;
    for (int tt = 1 ; tt <= TT; tt++) {
        int n;
        cin >> n;
        vector<string> w(n);
        trie.clear();
        vector<vector<int>> id(n);
        int maxK = 0;
        for (int i = 0; i < n; i++) {
            cin >> w[i];
            reverse(all(w[i]));
            id[i] = trie.insert(w[i]);
            maxK = max(maxK, sz(id[i]));
        }
        int q;
        cin >> q;
        vector<vector<Query>> v(maxK);
        for (int i = 0; i < q; i++) {
            int l, r, k;
            cin >> l >> r >> k;
            --l, --r;
            if (k < maxK) v[k].emplace_back(l, r);
        }
        ll ans = 0;
        vector<int> freq(trie.size(), 0);
        for (int k = 0; k < maxK; k++) {
            vector<int> count(n + 1, 0);
            sort(all(v[k]));
            auto add = [&](int i) {
                if (sz(id[i]) > k) {
                    int x = id[i][k];
                    freq[x]++;
                    count[freq[x]]++;
                }
            };
            auto erase = [&](int i) {
                if (sz(id[i]) > k) {
                    int x = id[i][k];
                    count[freq[x]]--;
                    freq[x]--;
                }
            };
            auto getAns = [&]() {
                int groups = n;
                for (int i = 1; i <= groups; i++) {
                    groups = min(groups, i - 1 + count[i]);
                }
                return groups;
            };            
            int curL = 0, curR = -1;
            for (auto [l, r] : v[k]) {
                while (l < curL) add(--curL);
                while (r > curR) add(++curR);
                while (l > curL) erase(curL++);
                while (r < curR) erase(curR--);
                ans += getAns();
            }
        }
        cout << "Case #" << tt << ": " << ans << '\n';
    }
}
