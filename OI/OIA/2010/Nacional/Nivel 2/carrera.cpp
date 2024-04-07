#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using vi = vector<int>;
using ii = pair<int, int>;

int main() {
    freopen("carrera.in", "r", stdin);
	freopen("carrera.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m[2], q;
    cin >> n >> m[0] >> m[1] >> q;
    vi categ[2];
    vector<vi> order[2];
    for (int i = 0; i < 2; i++) {
        categ[i].resize(m[i]);
        order[i].resize(m[i]);
        for (int j = 0; j < m[i]; j++) {
            int x;
            cin >> x >> categ[i][j];
        }
    }
    vector<ii> type(n);
    for (int i = 0; i < n; i++) {
        int e;
        char g;
        cin >> e >> g;
        int j = g == 'M';
        int k = int(lower_bound(all(categ[j]), e) - begin(categ[j]));
        type[i] = {j, k};
    }
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        auto [j, k] = type[x - 1];
        order[j][k].push_back(x);
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < m[i]; j++) {
            order[i][j].resize(3, 0);
            cout << j + 1 << ' ';
            for (int x : order[i][j]) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    
    return 0;
}
