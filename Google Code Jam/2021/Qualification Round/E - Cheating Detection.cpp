#include <bits/stdc++.h>

using namespace std;

const int N = 100;
const int M = 10000;

using ld = long double;

const ld INF = 1e18;

ld S[N], SC[N], Q[M];
string e[N];

inline ld f(ld x) {
    return log((exp(3.0) - exp(-3.0)) / (exp(6.0 * x) - 1.0) - exp(-3.0));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT, P;
    cin >> TT >> P;
    for (int tt = 1; tt <= TT; tt++) {
        for (int i = 0; i < N; i++) {
            cin >> e[i];
        }
        for (int i = 0; i < N; i++) {
            int cant = 0;
            for (int j = 0; j < M; j++) {
                if (e[i][j] == '1') cant++;
            }
            ld p = 1.0 - cant / ld(M);
            S[i] = f(p);
            SC[i] = f(2.0 * p);
            
        }
        for (int i = 0; i < M; i++) {
            int cant = 0;
            for (int j = 0; j < N; j++) {
                if (e[j][i] == '1') cant++;
            }
            ld p = cant / ld(N);
            Q[i] = f(p);
        }
        pair<ld, int> ans = {-INF, 0};
        for (int i = 0; i < N; i++) {
            ld probCheaterLog = 0.0;
            for (int j = 0; j < M; j++) {
                ld probCorrect = 1.0 / ld(1.0 + exp(Q[j] - S[i]));
                ld probCorrectCheater = 0.5 + 0.5 / ld(1.0 + exp(Q[j] - SC[i]));
                if (e[i][j] == '1') {
                    probCheaterLog += log(probCorrectCheater);
                    probCheaterLog -= log(probCorrect);
                } else {
                    probCheaterLog += log(1 - probCorrectCheater);
                    probCheaterLog -= log(1 - probCorrect);
                }
            }
            ans = max(ans, {probCheaterLog, i + 1});
        }
        cout << "Case #" << tt << ": " << ans.second << '\n';
    }
    
    return 0;
}
