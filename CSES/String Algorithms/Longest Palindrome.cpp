#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e6;
 
int p[2][MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    
    int n = ssize(s);
    pair<int, int> ans = {-1, 0};
    for (int c : {0, 1}) {
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int curr = i > r ? c : min(r - i + 1, p[c][l + r - i + 1 - c]);
            while (i + curr < n && i - curr + c >= 1 && s[i - curr - 1 + c] == s[i + curr]) {
                curr++;
            }
            p[c][i] = curr;
            if (i + curr - 1 > r) {
                l = i - curr + c;
                r = i + curr - 1;
            }
            ans = max(ans, {r - l + 1, l});
        }
    }
 
    auto [len, pos] = ans;
    cout << s.substr(pos, len) << '\n';
    
    return 0;
}