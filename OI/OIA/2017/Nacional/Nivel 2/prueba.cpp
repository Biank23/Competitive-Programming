#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

bool esPalindromo(string s) {
    int i = 0, j = sz(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}

int solve(string palabra) {
    for (int i = 0; i < sz(palabra); i++) {
        if (esPalindromo(palabra.substr(i))) {
            return i;
        }
    }
    assert(false);
}

int prueba(string palabra) {
    int ans = solve(palabra);
    reverse(all(palabra));
    ans = min(ans, solve(palabra));
    return ans;
}
