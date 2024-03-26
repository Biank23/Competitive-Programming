#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

const vector<pair<string, int>> v = {{"M", 1000},
                                     {"CM", 900},
                                     {"D", 500},
                                     {"CD", 400},
                                     {"C", 100},
                                     {"XC", 90},
                                     {"L", 50},
                                     {"XL", 40},
                                     {"X", 10},
                                     {"IX", 9},
                                     {"V", 5},
                                     {"IV", 4},
                                     {"I", 1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    map<string, int> val(all(v));
    map<int, int> chars;
    for (auto p : v) {
        chars[p.second] = sz(p.first);
    }
    
    ll ans = 0;
    string r;
    while (cin >> r) {
        int t = sz(r);
        int num = 0;
        r += '-';
        int i = 0;
        while (i < t) {
            string s = r.substr(i, 2);
            if (val.count(s)) {
                num += val[s];
                i += 2;
            } else {
                s.pop_back();
                num += val[s];
                i++;
            }
        }
        int length = 0;
        while (num > 0) {
            auto it = chars.upper_bound(num);
            assert(it != chars.begin());
            --it;
            num -= it->first;
            length += it->second;
        }
        ans += t - length;
    }
    cout << ans << '\n';
    
    return 0;
}
