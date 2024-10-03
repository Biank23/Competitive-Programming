#include <bits/stdc++.h>

using namespace std;

int code(int n) {
    if (n <= 2) return 1;
    if (n % 10 == 7) return code(n - 5) + 1;
    if (n % 4 == 0) return code(n / 4) + code(n / 2);
    return code(n + 1) + 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    cout << code(n) << '\n';
    
    return 0;
}