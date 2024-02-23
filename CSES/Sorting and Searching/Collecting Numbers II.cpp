#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> x(n), idx(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        --x[i];
        idx[x[i]] = i;
    }
    int rounds = 1;
    auto updateRounds = [&](int i, int v) {
        if (idx[i] < idx[i - 1]) rounds += v;
    };
    for (int i = 1; i < n; i++) {
        updateRounds(i, 1);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        set<int> indexesToUpdate = {x[a], x[a] + 1, x[b], x[b] + 1};
        for (int j : indexesToUpdate) {
            if (j > 0 && j < n) updateRounds(j, -1);
        }
        swap(x[a], x[b]);
        idx[x[a]] = a, idx[x[b]] = b;
        for (int j : indexesToUpdate) {
            if (j > 0 && j < n) updateRounds(j, 1);
        }
        cout << rounds << '\n';
    }
    
    return 0;
}