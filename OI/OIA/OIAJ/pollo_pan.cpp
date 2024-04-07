#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    int n = sz(s);
    cout << string(n + 2, '*') << '\n';
    cout << '*' << s << "*\n";
    cout << string(n + 2, '*') << '\n';
    
    return 0;
}
