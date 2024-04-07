#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    int p;
    cin >> s >> p;
    s[p - 1] = 'X';
    cout << s << '\n';
    
    return 0;
}
