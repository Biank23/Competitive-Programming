#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
const int MAX_X = 1e6 + 9;
 
int freq[MAX_X];
 
int maxGCD(vector<int> &v) {
    for (int &x : v) freq[x]++;
    int maxNum = *max_element(all(v));
    for (int i = maxNum; i > 1; i--) {
        int multiples = 0;
        for (int j = i; j <= maxNum; j += i) {
            multiples += freq[j];
        }
        if (multiples >= 2) return i;
    }
    return 1;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << maxGCD(v) << '\n';
    
    return 0;
}