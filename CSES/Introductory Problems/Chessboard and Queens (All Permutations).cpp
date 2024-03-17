#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x),end(x)
 
const int N = 8;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    vector<string> chessboard(N);
    for (auto &row : chessboard) {
        cin >> row;
    }
    
    vector<int> pos(N);
    iota(all(pos), 0);
    
    int ways = 0;
    do {
        bool flag = true;
        vector<bool> leftDiag(2 * N - 1, false), rightDiag(2 * N - 1, false);
        for (int i = 0; i < N; i++) {
            int j = pos[i];
            if (leftDiag[i + j] || rightDiag[N - 1 + j - i] || chessboard[i][j] == '*') {
                flag = false;
                break;
            }
            leftDiag[i + j] = rightDiag[N - 1 + j - i] = true;
        }
        if (flag) ways++;
    } while (next_permutation(all(pos)));
    cout << ways << '\n';
    
    return 0;
}
