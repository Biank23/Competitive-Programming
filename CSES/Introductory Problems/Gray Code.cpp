#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<string> bit_string(1<<n);
    int curr_size = 1;
    for (int i = 0; i < n; i++) {
        curr_size *= 2;
        for (int j = 0; j < curr_size / 2; j++) {
            bit_string[curr_size - 1 - j] = bit_string[j] + '1';
            bit_string[j] += '0';
        }
    }
    for (int i = 0; i < curr_size; i++) {
        cout << bit_string[i] << '\n';
    }
    
    return 0;
}
