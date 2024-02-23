#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
 
const int CANT_DIR = 4;
const int MAX_MOVES = 48;
const int SIZE_GRID = 9;
const ii TARGET = {7, 1};
 
const int dx[CANT_DIR] = {-1, 0, 1, 0};
const int dy[CANT_DIR] = {0, 1, 0, -1};
const map<char, int> dir = {{'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

bool vis[SIZE_GRID][SIZE_GRID];
int paths = 0;
string description;

void dfs(int x = 1, int y = 1, int m = 0) {
    if (vis[x][y - 1] == vis[x][y + 1] &&
        vis[x - 1][y] == vis[x + 1][y] &&
        vis[x][y - 1] != vis[x - 1][y]) return;
        
    ii position = {x, y};
    if (position == TARGET || m >= MAX_MOVES) {
        if (position == TARGET && m == MAX_MOVES) paths++;
        return;
    }
    
    auto move = [&](int i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (!vis[newX][newY]) {
            dfs(newX, newY, m + 1);
        }
    }; 
    
    vis[x][y] = true;
    char d = description[m];
    if (d != '?') {
        move(dir.at(d));
    } else {
        for (int i = 0; i < CANT_DIR; i++) {
            move(i);
        }
    }
    vis[x][y] = false;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> description;
    for (int i = 0; i < SIZE_GRID; i++) {
        vis[0][i] = true;
        vis[i][0] = true;
        vis[i][SIZE_GRID - 1] = true;
        vis[SIZE_GRID - 1][i] = true;
    }
    dfs();
    cout << paths << '\n';
    return 0;
}
