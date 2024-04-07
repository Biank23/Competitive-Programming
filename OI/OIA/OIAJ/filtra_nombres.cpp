#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char &c : s) {
            if (isupper(c)) {
                c = (char) tolower(c);
            }
        }
        if (s.front() == s.back()) {
            cout << s << '\n';
        }
    }
    
    return 0;
}
