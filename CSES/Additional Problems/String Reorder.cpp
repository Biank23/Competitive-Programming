#include <bits/stdc++.h>
 
using namespace std;
 
const int ALPHA = 26;
 
#define all(x) begin(x), end(x)
 
vector<int> freq(ALPHA, 0);
 
bool check(int p) {
    if (freq[p] == 0) return false;
    freq[p]--;
    int sum = accumulate(all(freq), 0);
    if (*max_element(all(freq)) <= (sum + 1) / 2 && freq[p] <= sum / 2) return true;
    freq[p]++;
    return false;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    
    for (char &c : s) {
        freq[c - 'A']++;
    }
    
    int prev = -1;
    for (char &c : s) {
        c = '-';
        for (int i = 0; i < ALPHA && c == '-'; i++) {
            if (i != prev && check(i)) {
                c = char('A' + i);
                prev = i;
            }
        }
        if (c == '-') {
            s = "-1";
            break;
        }
    }
    
    cout << s << '\n';
    
    return 0;
}