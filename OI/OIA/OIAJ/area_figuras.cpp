#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string figura;
    cin >> figura;
    
    if (figura == "cuadrado") {
        int lado;
        cin >> lado;
        cout << lado * lado << '\n';
    } else if (figura == "rectangulo") {
        int base, altura;
        cin >> base >> altura;
        cout << base * altura << '\n';
    } else if (figura == "cubo") {
        int lado;
        cin >> lado;
        cout << 6 * lado * lado << '\n';
    } else if (figura == "caja") {
        int ancho, largo, alto;
        cin >> ancho >> largo >> alto;
        cout << 2 * (ancho * largo + largo * alto + alto * ancho) << '\n';
    } else {
        assert(false);
    }
    
    return 0;
}
