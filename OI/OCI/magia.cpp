#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x),end(x)
#define pb push_back

using ll = long long;
using vs = vector<string>;

const string palo = "CDPT";
const vs valor = {"10", "2", "3", "4", "5", "6", "7", "8", "9", "A", "J", "K", "Q"};
vs t;

int gestos() {
    assert(t.empty());
    for (char p : palo) {
        for (string v : valor) t.pb(p + v);
    }
    return 1;
}

pair<vs, int> asistente(vs cartas, string elegida) {
    set<string> s;
    for (string c : cartas) {
        if (c != elegida) s.insert(c);
    }
    vs p;
    for (string c : t) {
        if (!s.count(c)) p.pb(c);
    }
    assert(sz(p) == 48);
    int pos = int(lower_bound(all(p), elegida) - begin(p));
    int gesto = 0;
    if(pos >= 24) {
        pos -= 24, gesto = 1;
    }
    cartas = vs(all(s));
    while (pos--) {
        next_permutation(all(cartas));
    }
    return {cartas, gesto};
}

string mago(vs cartas, int gesto) {
    set<string> s(all(cartas));
    vs p;
    for (string c : t) {
        if (!s.count(c)) p.pb(c);
    }
    assert(sz(p)==48);
    vs c(all(s));
    int pos=0;
    while (c != cartas) {
        pos++;
        next_permutation(all(c));
    }
    if (gesto) pos += 24;
    return p[pos];
}

