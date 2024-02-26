#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    
    int n = ssize(s);
    vector<int> pi(n);
    int j = pi[0] = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    
    stack<int> borders;
    while (j > 0) {
        borders.push(j);
        j = pi[j - 1];
    }
    
    while (!borders.empty()) {
        cout << borders.top() << ' ';
        borders.pop();
    }
    cout << '\n';
    
    return 0;
}