#include <bits/stdc++.h>

using namespace std;

string procesaPalabra(string palabra) {
    assert(!palabra.empty());
    palabra.pop_back();
    for (char &letra : palabra) {
        if (letra == 'A') letra = 'B';
    }
    return palabra;
}
