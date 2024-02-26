#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e6 + 5;
 
int divisors[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for (int i = 1; i < MAX_N; i++) {
        for (int j = i; j < MAX_N; j += i) {
            divisors[j]++;
        }
    }
    
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << divisors[x] << '\n';
    }
    
    return 0;
}