#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

string formaguarda(int N, string &tipo, string &patron) {
    string s = "";
    while (sz(s) < N) {
        s += patron;
        if (tipo == "ESPEJADA") {
            reverse(all(patron));
        }
    }
    s.resize(N);
    return s;
}
