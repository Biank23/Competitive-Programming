#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vs = vector<string>;
using ti = tuple<int, int, int>;

struct : map<string, int> {
    int& operator[](string &s) {
        if (!count(s)) {
            emplace(s, size());
        }
        return at(s);
    }
} m;

set<ti> r;

int autocompletando(int K, vs &r1, vs &r2, vs &r3, string &texto) {
    texto += ' ';
    for (int i = 0; i < sz(r1); i++) {
        r.emplace(m[r1[i]], m[r2[i]], m[r3[i]]);
    }
    string palabra = "";
    int a = -1, b = -1;
    for (int i = 0; i < sz(texto); i++) {
        if (texto[i] != ' ') {
            palabra += texto[i];
            continue;
        }
        
        int c = m[palabra];
        palabra = "";
        K--;
        if (a == -1) {
            a = c;
        } else if (b == -1) {
            b = c;
        } else {
            if (r.count(ti{a, b, c})) {
                K++;
            }
            tie(a, b) = make_pair(b, c);
        }
    }
    return K >= 0;
}
