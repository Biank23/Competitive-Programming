#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

string decimalToBinary(int num) {
    string bin = "";
    do {
        bin += '0' + num % 2;
    } while (num /= 2);
    return bin;
}

bool isPalindrome(string num) {
    string rev(rbegin(num), rend(num));
    return num == rev;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1e6;

    ll res = 0;
    for (int i = 0; i < N; i++) {
        if (isPalindrome(to_string(i)) && isPalindrome(decimalToBinary(i))) {
            res += i;
        }
    }
    cout << res << '\n';

    return 0;
}