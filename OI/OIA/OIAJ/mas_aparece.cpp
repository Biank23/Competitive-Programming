#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    const int X = 101;
    vector<int> freq(X, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    
    pair<int, int> ans = {0, 0};
    for (int i = 1; i < X; i++) {
        ans = max(ans, {freq[i], i});
    }
    cout << ans.second << ' ' << ans.first << '\n';
    
    return 0;
}
