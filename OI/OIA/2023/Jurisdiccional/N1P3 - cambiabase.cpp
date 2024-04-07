#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

vector<string> cambiabase(vector<int> &numeros, int base) {
    vector<string> v;
    for (int x : numeros) {
        string ans = "";
        do ans += char('0' + x % base);
        while (x /= base);
        reverse(all(ans));
        v.push_back(ans);
    }
    return v;
}
