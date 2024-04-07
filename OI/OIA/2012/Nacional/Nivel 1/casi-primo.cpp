#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("casi-primo.in", "r", stdin);
	freopen("casi-primo.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    vector<bool> esPrimo(max(c, b) + 1, true);
    esPrimo[0] = esPrimo[1] = false;
    for (int i = 2; i <= c; i++) {
        if (!esPrimo[i]) continue;
        for (int j = i * i; j <= b; j += i) {
            esPrimo[j] = false;
        }
    }
    int respuesta = 0;
    for (int i = max(a, c + 1); i <= b; i++) {
        if (esPrimo[i]) respuesta++;
    }
    cout << respuesta << '\n';
    
    return 0;
}
