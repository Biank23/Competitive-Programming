#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ii = pair<int, int>;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<ii> events(2 * n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        events[2 * i] = {l, 1};
        events[2 * i + 1] = {r + 1, -1};
    }
    sort(all(events));
    
    int costumers = 0, maxi = 0;
    for (auto [_, x] : events) {
        costumers += x;
        maxi = max(maxi, costumers);
    }
    cout << maxi << '\n';
    
    return 0;
}
