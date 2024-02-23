#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    nth_element(begin(p), begin(p) + n / 2, end(p));
    int median = p[n / 2];
    ll cost = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(p[i] - median);
    }
    cout << cost << '\n';
    
    return 0;
}