#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> vals(all(v));
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    for (int i = 0; i < n; i++) {
        v[i] = int(lower_bound(all(vals), v[i]) - begin(vals));
    }
    
    vector<int> count(n, 0);
    int l = 0, distinctValues = 0;
    ll cant = 0;
    for (int r = 0; r < n; r++) {
        count[v[r]]++;
        if (count[v[r]] == 1) {
            distinctValues++;
        }
        while (distinctValues > k) {
            count[v[l]]--;
            if (count[v[l]] == 0) {
                distinctValues--;
            }
            l++;
        }
        cant += r - l + 1;
    }
    cout << cant << '\n';
    
    
    return 0;
}