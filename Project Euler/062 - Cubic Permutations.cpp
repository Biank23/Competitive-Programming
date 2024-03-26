#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    const ll N = 1e4;
    
    struct : map<string, int> {
        int& operator[](string s) {
            sort(all(s));
            if (!count(s)) emplace(s, 0);
            return at(s);
        }
    } m;
    
    for (ll i = 0; i < N; i++) {
        m[to_string(i * i * i)]++;
    }
    
    string ans = "";
    for (ll i = 0; i < N; i++) {
        string num = to_string(i * i * i);
        if (m[num] == 5) {
            ans = num;
            break;
        }
    }
    assert(ans != "");
    cout << ans << '\n';
    
    return 0;
}
