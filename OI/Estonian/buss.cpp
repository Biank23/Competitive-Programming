#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int h, m, n;
    cin >> h >> m >> n;
    int t = h * 60 + m;
    ii ans = {-INF, -INF};
    for (int i = 1; i <= n; i++) {
        int j;
        cin >> h >> m >> j;
        int diff = (h * 60 + m) - (t + j);
        ans = max(ans, ii{diff, i});
    }
    if (ans.first >= 0) cout << "JAH\n";
    else cout << "EI\n";
    cout << ans.second << '\n';

    return 0;
}