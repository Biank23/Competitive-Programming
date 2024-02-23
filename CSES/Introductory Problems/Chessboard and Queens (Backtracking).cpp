#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 8;
 
string chessboard[N];
bool leftDiag[2 * N - 1], rightDiag[2 * N - 1], column[N];
int ways = 0;
 
void place(int row = 0) {
    if (row == N) {
        ways++;
        return;
    }
    
    for (int col = 0; col < N; col++) {
        if (chessboard[row][col] == '.' && !column[col] &&
            !leftDiag[row + col] && !rightDiag[N - 1 + col - row]) {
            column[col] = leftDiag[row + col] = rightDiag[N - 1 + col - row] = true;
            place(row + 1);
            column[col] = leftDiag[row + col] = rightDiag[N - 1 + col - row] = false;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for (int i = 0; i < N; i++) {
        cin >> chessboard[i];
    }
    place();
    cout << ways << '\n';
    
    return 0;
}
