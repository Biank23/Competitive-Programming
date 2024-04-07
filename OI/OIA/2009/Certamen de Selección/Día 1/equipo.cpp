#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

const int ALPHA = 26;

struct Node {
    int child[ALPHA];
    int cant = 0;
};

const int MAX_SIZE = 3e6;

Node trie[MAX_SIZE];
int trieSize = 1;

ll maxVal = 0LL;
int j = -1, k = -1;

void insert(string &s, int idx) {
    int u = 0;
    for (int i = 0; i < sz(s); i++) {
        int &v = trie[u].child[s[i] - 'a'];
        if (!v) v = trieSize++;
        u = v;
        trie[u].cant++;
        if (trie[u].cant > 1) {
            ll val = trie[u].cant * (i + 1LL) * (i + 1LL);
            if (val > maxVal) {
                maxVal = val;
                j = idx;
                k = i + 1;
            }
        }
    }
}

int main() {
    freopen("equipo.in", "r", stdin);
	freopen("equipo.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int p, n;
    cin >> p >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        insert(s[i], i);
    }
    cout << maxVal << '\n';
    cout << s[j].substr(0, k) << '\n';
    
    return 0;
}
