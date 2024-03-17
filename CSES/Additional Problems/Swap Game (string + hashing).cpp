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
                        
const string TARGET = "123456789";
                
int solve(string s) {
    queue<string> q;
    unordered_set<string> vis;
    q.push(s);
    vis.insert(s);
    
    int dist = 0;
    while(!q.empty()) {
        int sz = ssize(q);
        while (sz--) {
            string curr = q.front();
            q.pop();
            if(curr == TARGET) return dist;
            for (int i = 0; i < CANT_MOVES; i++) {
                auto [j, k] = moves[i];
                swap(curr[j], curr[k]);
                if(!vis.count(curr)) {
                    q.push(curr);
                    vis.insert(curr);
                }
                swap(curr[j], curr[k]);
            }
        }
        dist++;
    } 
    return dist;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s += char('0'+x);
    }
    
    cout << solve(s) << '\n';
    
    return 0;
}