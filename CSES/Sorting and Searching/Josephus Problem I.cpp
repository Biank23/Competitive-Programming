#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    bool remove = false;
    while (!q.empty()) {
        int child = q.front();
        q.pop();
        if (remove) {
            cout << child << ' ';
        } else {
            q.push(child);
        }
        remove ^= true;
    }
    cout << '\n';
    
    return 0;
}