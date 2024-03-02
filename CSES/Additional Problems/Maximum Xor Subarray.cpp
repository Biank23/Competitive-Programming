#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
const int MAX_K = 32;
const int MAX_SIZE = MAX_N * MAX_K;
const int ALPHA = 2;
 
int sig[MAX_SIZE][ALPHA];
int trieSize = 0;
 
void insert(int x) {
    int u = 0;
    for (int i = MAX_K - 1; i >= 0; i--) {
        int bit = x>>i & 1;
        int &v = sig[u][bit];
        if (v == 0) v = ++trieSize;
        u = v;
    }
}
 
int maxXor(int x) {
    int u = 0, res = 0;
    for (int i = MAX_K - 1; i >= 0; i--) {
        int bit = x>>i & 1;
        if (sig[u][bit ^ 1]) {
            res += 1<<i;
            u = sig[u][bit ^ 1];
        } else {
            u = sig[u][bit];
        }
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    int pref = 0, res = 0;
    for (int i = 0; i < n; i++) {
        insert(pref);
        int x;
        cin >> x;
        pref ^= x;
        res = max(res, maxXor(pref));
    }
    
    cout << res << '\n';
    
    return 0;
}