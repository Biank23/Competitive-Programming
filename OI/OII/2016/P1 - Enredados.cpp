#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1500001;

int ft[MAX_N], p[MAX_N];

void update(int i) {
    for (++i; i < MAX_N; i += i&-i) ft[i]++;
}

int query(int i) {
    int s = 0;
    for (; i > 0; i -= i&-i) s += ft[i];
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    n /= 2;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; --a;
        p[a] = i;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; --a;
        ans += query(n) - query(p[a]);
        update(p[a]);
    }
    cout << ans << '\n';
    
    return 0;
}