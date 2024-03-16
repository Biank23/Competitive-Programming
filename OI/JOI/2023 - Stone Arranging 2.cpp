#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    map<int, int> last;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        last[a[i]] = i;
    }
    for (int i = 0; i < n; i = last[a[i]] + 1) {
        for (int j = i; j < last[a[i]]; j++) {
            a[j] = a[i];
        }
    }
 
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    
    return 0;
}
