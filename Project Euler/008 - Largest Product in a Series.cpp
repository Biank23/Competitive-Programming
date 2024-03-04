#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int k = 13;
    //since k is small we can use a O(n * k) solution for this problem
    //but we are going to use a sliding window to improve it to O(n)
    string number;
    cin >> number;
    int n = sz(number);

    int zeros = 0;
    ll prod = 1;

    //add x to the sliding window
    auto add = [&](int x) {
        if (x == 0) zeros++;
        else prod *= x;
    };

    //erase x from the sliding window
    auto erase = [&](int x) {
        if (x == 0) zeros--;
        else prod /= x;
    };

    //get the product of numbers in the current window
    auto ask = [&]() {
        if (zeros > 0) return 0LL;
        else return prod;
    };

    ll res = 0;
    for (int i = 0; i < n; i++) {
        add(number[i] - '0');
        if (i >= k) erase(number[i - k] - '0');
        if (i >= k - 1) res = max(res, ask());
    }
    cout << res << '\n';

    return 0;
}