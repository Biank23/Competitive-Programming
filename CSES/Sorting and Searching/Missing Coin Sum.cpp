#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(all(x));
    ll smallestMissingSum = 1;
    for (int i = 0; i < n && x[i] <= smallestMissingSum; i++) {
        smallestMissingSum += x[i];
    }
    cout << smallestMissingSum << '\n';
    
    return 0;
}