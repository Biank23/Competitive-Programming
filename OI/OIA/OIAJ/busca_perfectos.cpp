#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1020;

int sum[MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            sum[j] += i;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (sum[i] == i) cout << i << '\n';
    }
    
    return 0;
}
