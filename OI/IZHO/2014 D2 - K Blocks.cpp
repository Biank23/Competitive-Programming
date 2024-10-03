#include <bits/stdc++.h>
 
using namespace std;
 
#define fst first
#define snd second
 
const int INF = 1e9;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= K; i++) {
        stack<pair<int, int>> st;
        for (int j = i - 1; j < N; j++) {
            int mini = dp[i - 1][j];
            while (!st.empty() && a[st.top().fst] <= a[j]) {
                mini = min(mini, st.top().snd);
                st.pop();
            }
            if (st.empty() || a[j] + mini < a[st.top().fst] + st.top().snd) {
                st.emplace(j, mini);
            }
            dp[i][j + 1] = a[st.top().fst] + st.top().snd;
        }
    }
    cout << dp[K][N] << '\n';
    
    return 0;
}