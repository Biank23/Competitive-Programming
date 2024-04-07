#include <string>
#include <vector>

using namespace std;

#define sz(x) int(x.size())

using vs = vector<string>;

int predictivo(vs &r1, vs &r2, vs &r3, string &texto) {
    vs palabras;
    string s = "";
    texto += " ";
    for (char letra : texto) {
        if (letra != ' ') {
            s += letra;
        } else {
            palabras.push_back(s);
            s = "";
        }
    }
    bool flag = false;
    for (int i = 2; i < sz(palabras); i++) {
        bool found = false;
        for (int j = 0; j < sz(r1); j++) {
            if (r1[j] == palabras[i - 2] &&
                r2[j] == palabras[i - 1] &&
                r3[j] == palabras[i]) {
                found = true;
            }
        }
        if (!found) {
            if (flag) return 0;
            flag = true;
        }
    }
    return 1;
}
