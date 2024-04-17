#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
 
const int ALPHA = 26;
 
struct Node {
    int fail;
    int child[26];
    int jump;
    vector<int> leaf;
    Node() {
        fail = -1;
        memset(child, -1, sizeof child);
        jump = -1;
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
    trie[0].jump = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < ALPHA; i++) {
            int &v = trie[u].child[i];
            int g = u == 0 ? 0 : trie[trie[u].fail].child[i];
            if (v != -1) {
                trie[v].fail = g;
                if (g != 0 && trie[g].leaf.empty()) trie[v].jump = trie[g].jump;
                else trie[v].jump = g;
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
 
void process(int u, int pos) {
    while (u != 0) {
        for (int id : trie[u].leaf) {
            ans[id] = pos;
        }
        trie[u].leaf.clear();
        u = trie[u].jump;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    int k;
    cin >> s >> k;
    vector<string> t(k);
    for (int i = 0; i < k; i++) {
        cin >> t[i];
        insert(t[i], i);
    }
    init();
    
    int u = 0;
    for (int i = 0; i < sz(s); i++) {
        u = trie[u].child[s[i] - 'a'];
        process(u, i + 1);
    }
    for (int i = 0; i < k; i++) {
        if (ans[i]) cout << ans[i] - sz(t[i]) + 1 << '\n';
        else cout << "-1\n";
    }
    
    return 0;
}
