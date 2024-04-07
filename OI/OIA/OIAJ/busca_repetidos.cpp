#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n = 0;
    set<int> s;
    int x;
    while (cin >> x) {
        if (x == 0) break;
        s.insert(x);
        n++;
    }
    
    if (sz(s) < n) {
        cout << "Hay repetidos\n";
    } else {
        cout << "No hay repetidos\n";
    }
    
    return 0;
}
