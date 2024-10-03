#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
 
struct Trie {
    struct Node {
        int child[2];
        Node() {
            child[0] = child[1] = 0;
        }
    };
    vector<Node> trie;
    Trie() {
        trie.clear();
        trie.push_back(Node());
    }
    void insert(int x) {
        int u = 0;
        for (int i = 29; i >= 0; i--) {
            int b = x >> i & 1;
            if (!trie[u].child[b]) {
                trie[u].child[b] = sz(trie);
                trie.push_back(Node());
            }
            u = trie[u].child[b];
        }
    }
    int search(int x) {
        int u = 0;
        int ans = 0;
        for (int i = 29; i >= 0; i--) {
            int b = x >> i & 1;
            if (trie[u].child[b ^ 1]) {
                ans += 1 << i;
                u = trie[u].child[b ^ 1];
            } else if (trie[u].child[b]) {
                u = trie[u].child[b];
            } else {
                return 0;
            }
        }
        return ans;
    }
};
 
int check(vector<int> &a, int x, int k) {
    Trie trie;
    int n = sz(a);
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 0; i < sz(a); i++) {
        pref[i + 1] = pref[i] ^ a[i];
        if (i >= k) {
            trie.insert(pref[i - k]);
            if (trie.search(pref[i + 1]) >= x) return i - k + 1;
        }
    }
    return 0;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int l = -1, r = n + 1;
    int ans = -1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        int i = check(a, x, m);
        if (i != 0) {
            l = m;
            ans = i;
        } else {
            r = m;
        }
    }
    cout << ans << ' ' << r << '\n';
    
    return 0;
}