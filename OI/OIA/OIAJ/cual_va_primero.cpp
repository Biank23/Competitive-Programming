#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string a, b;
    cin >> a >> b;
    if (a < b) {
        cout << "LA PRIMERA\n";
    } else if (b < a) {
        cout << "LA SEGUNDA\n";
    } else {
        cout << "IGUALES\n";
    }
    
    return 0;
}
