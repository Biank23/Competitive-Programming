#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x),end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(all(b));
    int i = 0, j = 0;
    int applicants = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            applicants++;
            i++, j++;
            continue;
        }
        
        if (a[i] > b[j]) {
            j++;
        } else {
            i++;
        }
    }
    cout << applicants << '\n';
    
    return 0;
}
