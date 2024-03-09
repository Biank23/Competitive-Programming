#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

int sq(int num) {return num * num;}

int fifthPower(int num) {
    return sq(sq(num)) * num;
}

int sumOfDigitFifthPowers(int num) {
    ll sum = 0;
    do sum += fifthPower(num % 10);
    while (num /= 10);
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //upperbound: the number has 6 or less digits
    //reason: 7*9^5 (the maximum sum with 7) is less than 1000000 (the minimum number of 7 digits)

    ll res = 0;
    for (int i = 10; i < 1e7; i++) {
        if (sumOfDigitFifthPowers(i) == i) res += i;
    }
    cout << res << '\n';

    return 0;
}