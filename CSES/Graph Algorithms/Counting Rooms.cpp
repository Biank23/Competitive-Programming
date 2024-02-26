#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1000;
 
string grid[MAX_N];
 
const int MOVES = 4;
const int dx[MOVES] = {0, 1, 0, -1};
const int dy[MOVES] = {1, 0, -1, 0};
 
int n, m;
 
bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}
 
void dfs(int x, int y) {
    grid[x][y] = '-';
    for (int i = 0; i < MOVES; i++) {
        if (valid(x + dx[i], y + dy[i]) && grid[x + dx[i]][y + dy[i]] == '.') {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                dfs(i, j);
                rooms++;
            }
        }
    }
    cout << rooms << '\n';
    
    return 0;
}