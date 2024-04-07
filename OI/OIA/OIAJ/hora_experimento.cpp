#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int h, m, s, d;
    cin >> h >> m >> s >> d;
    s += d;
    m += s / 60;
    s %= 60;
    h += m / 60;
    m %= 60;
    h %= 24;
    cout << h << ' ' << m << ' ' << s << '\n';
    
    return 0;
}
