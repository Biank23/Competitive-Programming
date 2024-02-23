#include <bits/stdc++.h>
 
using namespace std;
 
const int ALPHA = 26;
 
int freq[ALPHA], n;
vector<string> permutations;
 
void solve(string curr = "") {
    if (ssize(curr) == n) {
        permutations.push_back(curr);
        return;
    }
    
    for (int i = 0; i < ALPHA; i++) {
        if (freq[i] > 0) {
            --freq[i];
            solve(curr + char('a' + i));
            ++freq[i];
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    n = ssize(s);
    for (char &c : s) {
        freq[c - 'a']++;
    }
    solve();
    cout << ssize(permutations) << '\n';
    for (string &p : permutations) {
        cout << p << '\n';
    }
    
    return 0;
}
