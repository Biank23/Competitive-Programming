#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> movie(n);
    for (auto &[end, start] : movie) {
        cin >> start >> end;
    }
    sort(all(movie)); //sort by end
    
    multiset<int> s;
    for (int i = 0; i < k; i++) {
        s.insert(0);
    }
    int seen = 0;
    for (auto &[end, start] : movie) {
        auto it = s.upper_bound(start);
        if (it != begin(s)) {
            s.erase(prev(it));
            s.insert(end);
            seen++;
        }
    }
    cout << seen << '\n';
    
    return 0;
}