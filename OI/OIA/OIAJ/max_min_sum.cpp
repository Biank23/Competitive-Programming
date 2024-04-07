#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << *max_element(all(x)) << '\n';
    cout << *min_element(all(x)) << '\n';
    cout << accumulate(all(x), 0) << '\n';
    
    return 0;
}
