#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
 
const int ALPHA = 26;
 
struct Node {
    int fail;
    int child[26];
    int count;
    vector<int> leaf;
    Node() {
        fail = -1;
        memset(child, -1, sizeof child);
        count = 0;
        leaf.clear();
    }
};
 
const int MAX_N = 5e5 + 20;
 
Node trie[MAX_N];
int trieSize = 1;
 
void insert(string s, int id) {
    int u = 0;
    for (char c : s) {
        int &v = trie[u].child[c - 'a'];
        if (v == -1) v = trieSize++;
        u = v;
    }
    trie[u].leaf.push_back(id);
}
 
vector<int> adj[MAX_N];
 
void init() {
    queue<int> q;
    q.push(0);
    trie[0].fail = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < ALPHA; i++) {
            int &v = trie[u].child[i];
            int g = u == 0 ? 0 : trie[trie[u].fail].child[i];
            if (v != -1) {
                trie[v].fail = g;
                q.push(v);
            } else {
                v = g;
            }
        }
    }
    for (int i = 1; i < trieSize; i++) {
        adj[trie[i].fail].push_back(i);
    }
}
 
int ans[MAX_N];
 
int dfs(int u) {
    int c = trie[u].count;
    for (int v : adj[u]) {
        c += dfs(v);
    }
    for (int i : trie[u].leaf) {
        ans[i] = c;
    }
    return c;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    int k;
    cin >> s >> k;
    for (int i = 0; i < k; i++) {
        string t;
        cin >> t;
        insert(t, i);
    }
    init();
    
    int u = 0;
    for (char c : s) {
        u = trie[u].child[c - 'a'];
        trie[u].count++;
    }
    
    dfs(0);
    for (int i = 0; i < k; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}
