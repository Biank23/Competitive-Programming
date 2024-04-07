#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    auto suma = [](int c) { //1 + 2 + ... + c
        return c * (c + 1) / 2;
    };
    int sumaPares = 2 * suma(n / 2);
    int sumaImpares = 2 * suma((n + 1) / 2) - (n + 1) / 2;
    cout << sumaPares - sumaImpares << '\n';
    
    return 0;
}
