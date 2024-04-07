#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int main() {
    freopen("maniobra.in", "r", stdin);
	freopen("maniobra.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    const int N = 4, K = 2;
    vector<vector<int>> c(K, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cin >> c[j][i];
        }
    }
    for (int i = 0; i < K; i++) for (int j = 0; j < K; j++) {
        if (max(c[i][2 * j], c[i][2 * j + 1]) < min(c[i][2 - 2 * j], c[i][3 - 2 * j])) {
            cout << "0\n";
            return 0;
        }
    }
    int respuesta = 1;
    for (int i = 0; i < K; i++) {
        sort(all(c[i]));
        respuesta *= c[i][2] - c[i][1] + 1;
    }
    cout << respuesta << '\n';
    
    return 0;
}
