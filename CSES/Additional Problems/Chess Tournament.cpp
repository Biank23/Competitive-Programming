#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ii = pair<int, int>;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    set<ii> players;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > 0) players.emplace(x, i);
    }
    
    vector<ii> games;
    bool possible = true;
    while (!players.empty()) {
        auto [x, i] = *begin(players);
        players.erase(begin(players));
        vector<ii> toInsert;
        while (x > 0 && !players.empty()) {
            auto [y, j] = *rbegin(players);
            players.erase(prev(end(players)));
            --x, --y;
            games.emplace_back(i, j);
            toInsert.emplace_back(y, j);
            
        }
        if (x > 0) possible = false;
        players.insert(all(toInsert));
    }
    
    if (possible) {
        cout << ssize(games) << '\n';
        for (auto [i, j] : games) {
            cout << i << ' ' << j << '\n';
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}