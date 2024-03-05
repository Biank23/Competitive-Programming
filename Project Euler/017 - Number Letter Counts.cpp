#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int units[] = {0,
    /*one*/      3,
    /*two*/      3,
    /*three*/    5,
    /*four*/     4,
    /*five*/     4,
    /*six*/      3,
    /*seven*/    5,
    /*eight*/    5,
    /*nine*/     4,
    /*ten*/      3,
    /*eleven*/   6,
    /*twelve*/   6,
    /*thirteen*/ 8,
    /*fourteen*/ 8,
    /*fifteen*/  7,
    /*sixteen*/  7,
    /*seventeen*/9,
    /*eighteen*/ 8,
    /*nineteen*/ 8
    };

int tens[] = {0,
    /*ten*/     3,
    /*twenty*/  6,
    /*thirty*/  6,
    /*forty*/   5,
    /*fifty*/   5,
    /*sixty*/   5,
    /*seventy*/ 7,
    /*eighty*/  6,
    /*ninety*/  6
    };

int letters(int x) {
    if (x < 20) {
        return units[x];
    } else if (x < 100) {
        return tens[x / 10] + units[x % 10];
    } else if (x < 1000) {
        int L = units[x / 100] + /*hundred*/ 7;
        if (x % 100 != 0) L += /*and*/ 3 + letters(x % 100);
        return L;
    } else if (x == 1000) {
        return /*one thousand*/ 11;
    } else {
        assert(false);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1000;
    ll res = 0;
    for (int i = 1; i <= N; i++) {
        res += letters(i);
    }
    cout << res << '\n';

    return 0;
}