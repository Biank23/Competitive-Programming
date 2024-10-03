#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> x(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> h[i];
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        vector<int> st{l == 0 ? l : l - 1};
        int ans = 0;
        for (int i = l; i < r; i++) {
            st.push_back(i);
            while (sz(st) > 1 && (x[st.back()] - h[st.back()] >= x[st[sz(st) - 2]] ||
                                (x[st.back()] + h[st.back()] <= x[i + (i != n - 1)]))) {
                    st.pop_back(), ans++;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}