#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //read and parse the input
    string input;
    cin >> input;
    vector<string> names;
    string word = "";
    for (char c : input) {
        if (c != '"' && c != ',') {
            word += c;
        } else if (c == ',') {
            names.push_back(word);
            word = "";
        }
    }
    if (word != "") {
        names.push_back(word);
    }

    int res = 0;
    auto isTriangular = [](ll x) {
        // n * (n + 1) / 2 = x
        // n = (sqrt(8 * x + 1) - 1) / 2
        ll s = sqrt(8 * x + 1);
        return s * s == 8 * x + 1;
    };

    for (int i = 0; i < sz(names); i++) {
        ll val = 0;
        for (char letter : names[i]) {
            val += letter - 'A' + 1;
        }
        if (isTriangular(val)) {
            res++;
        }
    }
    cout << res << '\n';

    return 0;
}