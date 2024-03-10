#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

const int N = 10;

ll factorial[N];

void initFactorials() {
    factorial[0] = 1;
    for (int i = 1; i < N; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

ll sumOfDigitFactorials(ll num) {
    ll sum = 0;
    do sum += factorial[num % 10];
    while (num /= 10);
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //upperbound: the number has 7 or less digits
    //reason: 8*9! (the maximum sum with 8) is less than 10000000 (the minimum number of 8 digits)

    initFactorials();

    //if the number has <= 7 digits their maximum sum (so their maximum value too) is 7*9!
    ll MAX_NUM = 7 * factorial[9];

    ll res = 0;
    for (int i = 10; i < MAX_NUM; i++) {
        if (sumOfDigitFactorials(i) == i) res += i;
    }
    cout << res << '\n';

    return 0;
}