#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 1e6 + 9;
 
int divisor[MAX_N], mobius[MAX_N], freq[MAX_N];
 
void sieve() {
    for (int i = 2; i * i < MAX_N; i++) {
        if (divisor[i] != 0) continue;
        for (int j = i * i; j < MAX_N; j += i) {
            divisor[j] = i;
        }
    }
    for (int i = 2; i < MAX_N; i++) {
        if (divisor[i] == 0) divisor[i] = i;
    }
} 
 
void initMobius() {
    mobius[1] = 1;
    for (int i = 2; i < MAX_N; i++) {
        int j = i / divisor[i];
        if (j % divisor[i] == 0) {
            mobius[i] = 0;
        } else {
            mobius[i] = -mobius[j];
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    sieve();
    initMobius();
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    
    ll res = 0;
    for (int i = 1; i < MAX_N; i++) {
        if (mobius[i] == 0) continue;
        int multiples = 0;
        for (int j = i; j < MAX_N; j += i) {
            multiples += freq[j];
        }
        res += multiples * (multiples - 1LL) / 2LL * mobius[i];
    }
    cout << res << '\n';
    
    return 0;
}
