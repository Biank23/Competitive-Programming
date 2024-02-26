#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
const int MAX_X = 1e6 + 9;
 
int multiples[MAX_X];
 
void getDivisors(int x) {
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            multiples[i]++;
            if (i != x / i) multiples[x / i]++;
        }
    }
}
 
int maxGCD(vector<int> &v) {
    for (int &x : v) getDivisors(x);
    int maxNum = *max_element(all(v));
    for (int i = maxNum; i > 1; i--) {
        if (multiples[i] >= 2) return i;
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