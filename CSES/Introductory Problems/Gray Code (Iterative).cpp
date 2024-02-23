#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<string> bitString(1<<n);
    int currSize = 1;
    for (int i = 0; i < n; i++) {
        currSize *= 2;
        for (int j = 0; j < currSize / 2; j++) {
            bitString[currSize - 1 - j] = bitString[j] + '1';
            bitString[j] += '0';
        }
    }
    for (int i = 0; i < currSize; i++) {
        cout << bitString[i] << '\n';
    }
    
    return 0;
}
