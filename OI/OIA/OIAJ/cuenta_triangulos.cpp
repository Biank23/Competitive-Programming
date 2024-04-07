#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 101;

struct FTree {
    int ft[MAX_N];
    FTree() {
        memset(ft, 0, sizeof ft);
    }
    void update(int i) {
        for (++i; i < MAX_N; i += i&-i) {
            ft[i]++;
        }
    }
    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i&-i) {
            s += ft[i];
        } 
        return s;
    }
    int query(int l, int r) {
        return query(r) - query(l);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        FTree ft;
        for (int j = 0; j < i; j++) {
            ans += ft.query(abs(x[i] - x[j]) + 1, min(x[i] + x[j], MAX_N - 1));
            ft.update(x[j]); // k < j
        }
    }
    cout << ans << '\n';
    
    return 0;
}
