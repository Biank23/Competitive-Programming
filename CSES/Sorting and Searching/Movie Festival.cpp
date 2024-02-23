#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ii = pair<int, int>;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<ii> movies(n);
    for (auto &[l, r] : movies) {
        cin >> l >> r;
    }
    sort(all(movies), [](const ii &a, const ii &b){
        return a.second < b.second;
    });
    
    int currR = 0, watched = 0;
    for (auto [l, r] : movies) {
        if (l >= currR) {
            watched++;
            currR = r;
        }
    }
    cout << watched << '\n';
    
    return 0;
}
