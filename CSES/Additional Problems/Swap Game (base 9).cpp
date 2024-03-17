#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
 
const int n = 9;
 
/* grid 
 * 0 1 2
 * 3 4 5
 * 6 7 8
 */
 
const int CANT_MOVES = 12;
 
ii moves[CANT_MOVES] = {{0, 1},{1, 2},
                        {3, 4},{4, 5},
                        {6, 7},{7, 8},
                        {0, 3},{3, 6},
                        {1, 4},{4, 7},
                        {2, 5},{5, 8}};
                        
 
const int pow9[10] = {1, 9, 81, 729, 6561, 59049, 531441,
                        4782969, 43046721, 387420489};
bool vis[387420489];
 
const int TARGET = 381367044;
            
int swap(int num, int i, int j) {
    int a = num % pow9[i + 1] / pow9[i];
    int b = num % pow9[j + 1] / pow9[j];
    return num + (b - a) * (pow9[i] - pow9[j]);
}
                
int solve(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    
    int dist = 0;
    while(!q.empty()) {
        int sz = ssize(q);
        while (sz--) {
            int u = q.front();
            q.pop();
            if(u == TARGET) return dist;
            for (int i = 0; i < CANT_MOVES; i++) {
                auto [j, k] = moves[i];
                int v = swap(u, j, k);
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        dist++;
    } 
    return dist;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int s = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s += (x - 1) * pow9[i];
    }
    
    cout << solve(s) << '\n';
    
    return 0;
}