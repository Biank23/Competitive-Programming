#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1005;
 
int p[MAX_N][MAX_N];
string s[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p[i + 1][j + 1] = p[i][j + 1] + p[i + 1][j] - p[i][j] + (s[i][j] == '*');
        }
    }
    
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1;
        cout << p[x2][y2] - p[x1][y2] - p[x2][y1] + p[x1][y1] << '\n';
    }
    
    return 0;
}