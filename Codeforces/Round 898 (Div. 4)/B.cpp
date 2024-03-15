#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < a[j]) j = i;
        }
        a[j]++;
        int prod = 1;
        for (int i = 0; i < n; i++) {
            prod *= a[i];
        }
        cout << prod << '\n';
    }
    
    return 0;
}
