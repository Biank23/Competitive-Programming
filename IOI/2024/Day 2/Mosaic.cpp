#include <bits/stdc++.h>
 
using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;
using ll = long long;
using vll = vector<ll>;

vi build_next(vi &curr, int first) {
    int n = sz(curr);
    vi nxt(n);
    nxt[0] = first;
    for (int i = 1; i < n; i++) {
        nxt[i] = !nxt[i - 1] && !curr[i];
    }
    return nxt;
}

template<typename T>
vll build_prefix(vector<T> &v) {
    int n = sz(v);
    vll pref(n + 1);
    pref[0] = 0LL;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }
    return pref;
}

vll mosaic(vi X, vi Y, vi T, vi B, vi L, vi R) {
    int n = sz(X), q = sz(L);
    int K = min(3, n);
    vector<vi> row(K), col(K);
    row[0] = X, col[0] = Y;
    for (int i = 0; i < K - 1; i++) {
        row[i + 1] = build_next(row[i], Y[i + 1]);
        col[i + 1] = build_next(col[i], X[i + 1]);
    }
    vector<vll> row_prefix(K), col_prefix(K);
    for (int i = 0; i < K; i++) {
        row_prefix[i] = build_prefix(row[i]);
        col_prefix[i] = build_prefix(col[i]);
    }
    int mini = -n + K + 1, maxi = n - K - 1;
    int m = max(0, maxi - mini + 1);
    vi diag(m);
    vll diag2(m), diag3(m);
    for (int diff = mini; diff <= maxi; diff++) {
        int i = diff - mini;
        if (diff < 0) {
            diag[i] = row[K - 1][K - 1 - diff];
        } else {
            diag[i] = col[K - 1][diff + K - 1];
        }
        diag2[i] = (i + 1LL) * diag[i];
        diag3[i] = 1LL * (m - i) * diag[i];
    }
    vll diag_pref = build_prefix(diag);
    vll diag2_pref = build_prefix(diag2);
    vll diag3_pref = build_prefix(diag3);

    auto rectangle_query = [&](int l, int r, int h) {
        if (l > r) return 0LL;
        return (diag_pref[r + 1] - diag_pref[l]) * h;
    };

    auto triangle_query1 = [&](int l, int r) {
        return diag2_pref[r + 1] - diag2_pref[l] - rectangle_query(l, r, l);
    };

    auto triangle_query2 = [&](int l, int r) {
        return diag3_pref[r + 1] - diag3_pref[l] - rectangle_query(l, r, m - 1 - r);
    };

    function<ll(int, int, int, int)> query = [&](int t, int b, int l, int r) {
        if (l > r || t > b) return 0LL;
        if (l < K) return col_prefix[l][b + 1] - col_prefix[l][t] + query(t, b, l + 1, r);
        if (t < K) return row_prefix[t][r + 1] - row_prefix[t][l] + query(t + 1, b, l, r);
        int n = min(b - t + 1, r - l + 1);
        int min_diff = t - r - mini, max_diff = b - l - mini;
        if (b - t == r - l) return triangle_query1(min_diff, min_diff + n - 1) + triangle_query2(min_diff + n, max_diff);
        return triangle_query1(min_diff, min_diff + n - 1) + rectangle_query(min_diff + n, max_diff - n, n) + triangle_query2(max_diff - n + 1, max_diff);
    };

    vll res(q);
    for (int i = 0; i < q; i++) {
        res[i] = query(T[i], B[i], L[i], R[i]);
    }

    return res;
}
