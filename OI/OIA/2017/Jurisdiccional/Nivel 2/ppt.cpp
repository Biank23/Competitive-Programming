#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string a, b;
    cin >> a >> b;
    
    if (a != b) {
        if ((a == "Piedra" && b == "Tijera") ||
            (a == "Tijera" && b == "Papel")  ||
            (a == "Papel" && b == "Piedra")) {
            cout << "Ana\n";
        } else {
            cout << "Bartolo\n";
        }
    } else {
        cout << "Empate\n";
    }
    
    return 0;
}
