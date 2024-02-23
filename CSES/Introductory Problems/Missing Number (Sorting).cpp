#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int i = 1;
    while (i < n && a[i - 1] == i) {
        i++;
    }
    cout << i << '\n';
    
    return 0;
}
