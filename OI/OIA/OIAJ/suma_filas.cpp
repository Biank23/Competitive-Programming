#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> fil(n, 0), col(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            fil[i] += x;
            col[j] += x;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << fil[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < m; i++) {
        cout << col[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
