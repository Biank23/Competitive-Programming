#include <bits/stdc++.h>
 
using namespace std;
 
const int ALPHA = 26;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    vector<int> freq(ALPHA, 0);
    for (char &c : s) {
        freq[c - 'A']++;
    }
    int odd = 0;
    for (int i = 0; i < ALPHA; i++) {
        if (freq[i] % 2 == 1) odd++;
    }
    int n = ssize(s);
    if (n % 2 != odd) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    int l = 0, r = n - 1;
    for (int i = 0; i < ALPHA; i++) {
        char c = char('A' + i);
        if (freq[i] % 2 == 1) {
            s[n / 2] = c;
            freq[i]--;
        }
        while (freq[i] > 0) {
            s[l++] = c;
            s[r--] = c;
            freq[i] -= 2;
        }
    }
    cout << s << '\n';
    
    return 0;
}
