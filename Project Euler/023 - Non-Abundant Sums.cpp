#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //it was given that the numbers greater
    //than 28123 can be written as the sum
    //of two abundant numbers
    const int N = 28124;

    //d[i] sum of proper divisors of i
    ll d[N] = {0};

    for (int i = 1; i < N; i++) {
        for (int j = 2 * i; j < N; j += i) {
            d[j] += i;
        }
    }

    vector<int> abundant;
    for (int i = 1; i < N; i++) {
        if (d[i] > i) abundant.push_back(i);
    }

    ll res = 0;
    for (int x = 1; x < N; x++) {
        bool can = false;
        for (int a : abundant) {
            if (a > x) break;
            int b = x - a;
            if (d[b] > b) {
                can = true;
                break;
            }
        }
        if (!can) res += x;
    }
    cout << res << '\n';

    return 0;
}