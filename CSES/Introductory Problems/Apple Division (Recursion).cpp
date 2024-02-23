#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 20;
 
int p[MAX_N], n;
ll tot = 0;
 
ll getMinDiff(int i = 0, ll sum = 0) {
    if (i == n) {
        ll otherSum = tot - sum;
        return abs(sum - otherSum);
    }
    return min(getMinDiff(i + 1, sum), getMinDiff(i + 1, sum + p[i]));
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        tot += p[i];
    }
    cout << getMinDiff() << '\n';
    
    
    return 0;
}
