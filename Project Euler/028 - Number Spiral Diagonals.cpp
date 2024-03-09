#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1001; //odd n
    int layers = N / 2;
    ll sum = 1, num = 1; //start with the center
    ll diff = 2; //current difference between consecutive numbers on the diagonals
    for (int i = 0; i < layers; i++) {
        for (int j = 0; j < 4; j++) {
            num += diff;
            sum += num;
        }
        diff += 2; //move to the next layer
    }
    cout << sum << '\n';

    return 0;
}