#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5;
 
int preorder[MAX_N], inorder[MAX_N];
int posInorder[MAX_N], p = -1;
 
void solve(int l, int r) {
    if (l > r) return;
    int m = posInorder[preorder[++p]];
    solve(l, m - 1);
    solve(m + 1, r);
    cout << inorder[m] + 1 << ' ';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
        preorder[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        inorder[i]--;
        posInorder[inorder[i]] = i;
    }
    solve(0, n - 1);
    
    return 0;
}