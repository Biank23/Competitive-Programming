#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using vi = vector<int>;

const int MOD = 1e9 + 7;

int ways(const vi &A, const vi &B, int maxi) {
    int j = 0, res = 1;
    for (int i = 0; i < sz(A); i++) {
        while (j < sz(B) && A[i] + B[j] <= maxi) j++;
        res = 1LL * res * (j - i) % MOD;
    }
    if (res < 0) res = 0;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi A(n), B(n);
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;
    sort(all(B));

    vi C(n, 0);
    for (int i = 0; i < n; i++) {
        vi a; a.reserve(n - 1);
        for (int j = 0; j < n; j++) {
            if (i != j) a.push_back(A[j]);
        }
        for (int j = 0; j < n; j++) {
            vi b; b.reserve(n - 1);
            for (int k = 0; k < n; k++) {
                if (j != k) b.push_back(B[k]);
            }
            C[i] += ways(a, b, A[i] + B[j]);
            if (C[i] >= MOD) C[i] -= MOD;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << C[i] << '\n';
    }

    return 0;
}