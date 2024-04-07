#include <bits/stdc++.h>
 
using namespace std;

#define sz(x) int(x.size())

const int ALPHA = 26;
 
struct Node {
    int adj[ALPHA];
    bool isEnd = false;
};
 
const int MAX_N = 1e5 + 20;
 
Node trie[MAX_N];
int trieSize = 0;
 
void insert(string &s) {
    int u = 0;
    for (char &c : s) {
        int &v = trie[u].adj[c - 'A'];
        if (!v) v = ++trieSize;
        u = v;
    }
    trie[u].isEnd = true;
}
 
int dp[MAX_N];
 
void search(string &s, int j) {
    int u = 0;
    for (int i = j; i < sz(s); i++) {
        int v = trie[u].adj[s[i] - 'A'];
        if (!v) return;
        u = v;
        if (trie[u].isEnd) {
            dp[i + 1] = min(dp[i + 1], dp[j]);
        }
    }
}

int cubrecadena(string &S, vector<string> &t) {
    for (int i = 0; i < sz(t); i++) {
        insert(t[i]);
    }
    int n = sz(S);
    for (int i = 0; i <= n; i++) {
        dp[i] = i;
    }
    for (int i = 0; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        search(S, i);
    }
    return dp[n];
}
