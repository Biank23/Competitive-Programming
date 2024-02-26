#include <bits/stdc++.h>
 
using namespace std;
 
const int ALPHA = 26;
 
struct Node {
    int adj[ALPHA];
    bool isEnd = false;
};
 
const int MAX_SIZE = 1e6+20;
 
Node trie[MAX_SIZE];
int trieSize = 0;
 
void insert(string &s) {
    int u = 0;
    for (char &c : s) {
        int &v = trie[u].adj[c - 'a'];
        if (!v) v = ++trieSize;
        u = v;
    }
    trie[u].isEnd = true;
}
 
const int MAX_N = 5005;
const int MOD = 1e9+7;
 
int dp[MAX_N];
 
void search(string &s, int j) {
    int u = 0;
    for (int i = j; i < ssize(s); i++) {
        int v = trie[u].adj[s[i] - 'a'];
        if (!v) return;
        u = v;
        if (trie[u].isEnd) {
            dp[i + 1] += dp[j];
            if (dp[i + 1] >= MOD) {
                dp[i + 1] -= MOD;
            }
        }
    }
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
        insert(t);
    }
    
    dp[0] = 1;
    int n = ssize(s);
    for (int i = 0; i < n; i++) {
        search(s, i);
    }
    cout << dp[n] << '\n';
    
    return 0;
}