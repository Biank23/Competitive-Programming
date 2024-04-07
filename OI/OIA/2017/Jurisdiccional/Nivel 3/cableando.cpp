#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int mini = k, maxi = k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mini = min(mini, x);
        maxi = max(maxi, x);
    }
    cout << maxi - mini << '\n';
    
    return 0;
}
