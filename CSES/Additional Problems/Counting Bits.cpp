#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const int MAX_K = 49;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;
    
    ll setBits = 0;
    for (int i = MAX_K; i >= 0; i--) {
        if (n>>i&1) {
            n -= 1LL<<i;
            setBits += (1LL<<(i-1)) * i + n + 1;
        }
    }
    cout << setBits << '\n';
    
    return 0;
}