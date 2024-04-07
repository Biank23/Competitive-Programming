#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    reverse(all(s));
    cout << s << '\n';
    
    return 0;
}
