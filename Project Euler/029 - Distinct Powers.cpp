#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 100;
    set<double> powers; //cannot use long long (100^100 > 2^63)
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            powers.insert(pow(a,b));
        }
    }
    cout << sz(powers) << '\n';

    return 0;
}