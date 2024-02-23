#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    
    int r = 1, best = 1;
    for (int i = 1; i < ssize(s); i++) {
        if (s[i] == s[i - 1]) {
            r++;
            best = max(best, r);
        } else {
            r = 1;
        }
    }
    cout << best << '\n';
    
    return 0;
}
