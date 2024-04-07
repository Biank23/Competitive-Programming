#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

void intercambia(string &s, bool b = true) {
    for (char &c : s) {
        if (isupper(c)) {
            c = (char) tolower(c);
        } else if (b) {
            c = (char) toupper(c);
        }
    }
}

pair<int, int> parse(string s) {
    string i = "";
    int p = 0;
    while (s[p] != '-') {
        i += s[p++];
    }
    p++;
    string j = "";
    while (p < sz(s)) {
        j += s[p++];
    }
    return {stoi(i) - 1, stoi(j) - 1};
}

string procesatexto(string &texto, vector<string> &comandos) {
    for (string c : comandos) {
        if (c == "INTERCAMBIA") {
            intercambia(texto);
        } else if (c == "BORRAULTI") {
            if (!texto.empty()) {
                texto.pop_back();
            }
        } else if (c == "BORRAPRI") {
            if (!texto.empty()) {
                texto = texto.substr(1);
            }
        } else if (c == "DUP") {
            texto += texto;
        } else if (c == "ROTA") {
            if (!texto.empty()) {
                texto = texto.substr(1) + texto.front();
            }
        } else if (c == "INVERTIR") {
            reverse(all(texto));
        } else if (c == "CHAUAGUS") {
            string copy = texto;
            intercambia(copy, false);
            size_t p = copy.find("agus");
            if (p != string::npos) {
                texto.erase(p, 4);
            }
        } else if (c.substr(0, 6) == "AGREGA") {
            string alpha = c.substr(7);
            texto += alpha;
        } else if (c.substr(0, 3) == "DUP") {
            auto [i, j] = parse(c.substr(4));
            texto.insert(j + 1, texto.substr(i, j - i + 1));
        } else if (c.substr(0, 8) == "INVERTIR") {
            auto [i, j] = parse(c.substr(9));
            reverse(begin(texto) + i, begin(texto) + j + 1);
        } else if (c.substr(0, 5) == "BORRA") {
            int i = stoi(c.substr(6)) - 1;
            texto.erase(begin(texto) + i);
        } else if (c.substr(0, 4) == "CHAU") {
            string alpha = c.substr(5);
            size_t p = texto.find(alpha);
            if (p != string::npos) {
                texto.erase(p, sz(alpha));
            }
        } else {
            assert(false);
        }
        if (sz(texto) > 1000) {
            return "MemoryLimitExceeded";
        }
    }
    return texto;
}
