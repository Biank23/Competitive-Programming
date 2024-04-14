#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;
using vvi = vector<vi>;

vi minimumSlidingWindow(vi &v, int k) {
    vi m;
    deque<int> dq;
    for (int i = 0; i < sz(v); i++) {
        while (!dq.empty() && v[dq.back()] >= v[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k && dq.front() == i - k) dq.pop_front();
        if (i >= k - 1) m.push_back(v[dq.front()]);
    }
    return m;
}

void apply(vector<vector<vvi>> &v, int m) {
    for (int i = 0; i < sz(v); i++) {
        for (int j = 0; j < sz(v[i]); j++) {
            for (int k = 0; k < sz(v[i][j]); k++) {
                v[i][j][k] = minimumSlidingWindow(v[i][j][k], m);
            }
        }
    }
}

vector<vector<vvi>> transpose(vector<vector<vvi>> &v) {//i -> j, j -> k, k -> l, l -> i
    int A = sz(v), B = sz(v[0]), C = sz(v[0][0]), D = sz(v[0][0][0]);
    vector<vector<vvi>> t(B, vector<vvi>(C, vvi(D, vi(A))));
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < C; k++) {
                for (int l = 0; l < D; l++) {
                    t[j][k][l][i] = v[i][j][k][l];
                }
            }
        }
    }
    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<vvi>> v(n, vector<vvi>(n, vvi(n, vi(n))));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    cin >> v[i][j][k][l];
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        apply(v, m);
        v = transpose(v);
    }
    n -= m - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    cout << v[i][j][k][l] << ' ';
                }
            }
        }
    }
    
    return 0;
}
