#include <bits/stdc++.h>
 
using namespace std;
 
using vs = vector<string>;
 
vs grayCode(int n) {
    if (n == 0) return {""};
    vs prev = grayCode(n - 1);
    vs curr;
    for (int i = 0; i < ssize(prev); i++) {
        curr.push_back(prev[i] + '0');
    }
    for (int i = ssize(prev) - 1; i >= 0; i--) {
        curr.push_back(prev[i] + '1');
    }
    return curr;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (auto bitString : grayCode(n)) {
        cout << bitString << '\n';
    }
    
    return 0;
}
