#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

const vector<pair<int, int>> v{{3, 2}, {7, 4}, {11, 5}, {13, 6}, {17, 7}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 9;

    string num = "";
    for (int i = 0; i <= N; i++) {
        num += char('0' + i);
    }
    ll res = 0;
    auto check = [](string num) {
        if (num[0] == '0') return false;
        if ((num[3] - '0') % 2 != 0) return false;
        if ((num[5] - '0') % 5 != 0) return false; 
        for (auto [d, i] : v) {
            if (stoi(num.substr(i, 3)) % d != 0) return false;
        }
        return true;
    };
    do {
        if (check(num)) res += stoll(num);
    } while (next_permutation(all(num)));
    cout << res << '\n';

    return 0;
}