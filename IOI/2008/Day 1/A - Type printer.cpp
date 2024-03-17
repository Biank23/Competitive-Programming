#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int MAX_N = 5e5 + 5;
const int ALPHA = 26;

struct Node {
    int child[ALPHA];
    bool isEnd = false, isLongest = false;
};

Node trie[MAX_N];
int trieSize = 0;

void insert(string s, bool longest) {
    int u = 0;
    for (char c : s) {
        int &v = trie[u].child[c - 'a'];
        if (v == 0) v = ++trieSize;
        u = v;
        if (longest) trie[u].isLongest = true;
    }
    trie[u].isEnd = true;
}

string ans = "";

void dfs(int u) {
    if (trie[u].isEnd) ans += 'P';
    int j = -1;
    for (int i = 0; i < ALPHA; i++) {
        int v = trie[u].child[i];
        if (v == 0) continue;
        if (trie[v].isLongest) {
            j = i;
        } else {
            ans += char('a' + i);
            dfs(v);
        }
    }
    if (j != -1) {
        ans += char('a' + j);
        int v = trie[u].child[j];
        dfs(v);
    }
    if (u != 0 && !trie[u].isLongest) ans += '-';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<string> word(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        cin >> word[i];
        if (sz(word[i]) > sz(word[j])) {
            j = i;
        }
    }
    for (int i = 0; i < n; i++) {
        insert(word[i], i == j);
    }
    
    dfs(0);
    cout << sz(ans) << '\n';
    for (char i : ans) {
        cout << i << '\n';
    }
    
    return 0;
}
