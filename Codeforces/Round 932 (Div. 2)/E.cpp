#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

struct STree {
    int n;
    vi st;
    STree(int _n) : n(_n), st(2 * n, 0) {}
    void init(vi &v) {
        for (int i = 0; i < n; i++) {
            st[i + n] = v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            st[i] = st[2 * i] | st[2 * i + 1];
        }
    }
    int query(int l, int r) {
        int ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) ans |= st[l++];
            if (r & 1) ans |= st[--r];
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi x(n), y(n), p(n);
        vector<vi> pref(n + 1, vi(31, 0));
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            for (int j = 30; j >= 0; j--) {
                if ((x[i] >> j & 1) != (y[i] >> j & 1)) {
                    break;
                }
                if (y[i] >> j & 1) {
                    p[i] |= 1 << j;
                    x[i] ^= 1 << j;
                    y[i] ^= 1 << j;
                }
            }
            for (int j = 0; j < 31; j++) {
                pref[i + 1][j] += pref[i][j];
                if (y[i] >> j & 1) pref[i + 1][j]++;
            }
        }
        STree st(n);
        st.init(p);
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r; --l;
            int ans = st.query(l, r);
            for (int j = 30; j >= 0; j--) {
                int cant = pref[r][j] - pref[l][j] + (ans >> j & 1);
                if (cant > 0) ans |= 1 << j;
                if (cant > 1) ans |= (1 << j) - 1;
            } 
            cout << ans << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}