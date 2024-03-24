#include <bits/stdc++.h>

using namespace std;

bool query(int c, int d) {
    assert(1 <= c && c <= 200);
    assert(1 <= d && d <= 200);
    cout << "? " << c << ' ' << d << endl;
    bool ans;
    cin >> ans;
    return ans;
}

int main() {
    
    int l = 0, r = 101;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (query(m, m)) l = m;
        else r = m;
    }
    
    int a = l;
    l = 0, r = 101;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (query(a, m)) l = m;
        else r = m;
    }
    int b = l;
    cout << "! " << a << ' ' << b << endl;
    
    return 0;
}
