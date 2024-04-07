#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2024;

using ll = long long;

int a[MAX_N][MAX_N];
ll col[MAX_N][MAX_N];
ll diag[MAX_N][MAX_N];

int main() {
    freopen("latas.in", "r", stdin);
	freopen("latas.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
            tot += a[i][j];
        }
    }
    int k = n;
    n *= 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            col[i + 1][j] = col[i][j] + a[i][j];
            diag[i + 1][j] = diag[i][j + 1] + a[i][j];
        }
    }
    ll suma = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < (k - i); j++) {
            suma += a[i][j];
        }
    }
    ll anterior = suma;
    ll maxi = suma;
    for (int i = 0; i < n - k; i++) {
        for (int j = 0; j < n - k; j++) {
            suma += diag[i + k][j + 1] - diag[i][j + k + 1];
            suma -= col[i + k][j] - col[i][j];
            maxi = max(maxi, suma);
        }
        for (int j = 0; j < k; j++) {
            anterior -= a[i][j];
            anterior += a[i + (k - j)][j];
        }
        suma = anterior;
        maxi = max(maxi, suma);
    }
    cout << tot - maxi << '\n';
    
    return 0;
}
