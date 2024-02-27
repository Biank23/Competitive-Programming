#include <bits/stdc++.h>
#pragma GCC target("popcnt")
 
using namespace std;
 
using ull = unsigned long long;
 
const int MAX_N = 3000;
const int WORD_SIZE = 64;
const int WORDS = MAX_N / WORD_SIZE + 1;
 
ull mat[MAX_N][WORDS];
 
int scanint() {
    int num = 0;
    char ch = getchar_unlocked();
    while (ch >= '0' && ch<='9') {
        num = (num << 1) + (num << 3) + ch - '0';
        ch = getchar_unlocked();
    }
    return num;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n = scanint();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (getchar_unlocked() == '1') mat[i][j >> 6] |= 1ULL << (j&63);
        }
        getchar_unlocked();
    }
    
    ull res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int c = 0;
            for (int k = 0; k < WORDS; k++) {
                c += __builtin_popcountll(mat[i][k] & mat[j][k]);
            }
            res += c * (c - 1) / 2;
        }
    }
    cout << res << '\n';
    
    return 0;
}