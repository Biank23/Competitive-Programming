#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ii = pair<int, int>;

const int N = 1000;

int a[N];
vector<ii> op;

void operation(int x, int y) {
    if (a[y] == 0 || x == y) return;
    a[x] ^= a[y];
    op.emplace_back(x + 1, y + 1);
}

void swap(int x, int y) {
    operation(x, y);
    operation(y, x);
    operation(x, y);
}

vector<vector<int>> getCycles(int n) {
    vector<int> p(n);
    iota(all(p), 0);
    stable_sort(all(p), [&](int x, int y) {
        return a[x] < a[y];
    });
    vector<bool> done(n, false);
    vector<vector<int>> cycles;
    for (int i = 0; i < n; i++) {
        if (done[i]) continue;
        vector<int> c;
        while (!done[i]) {
            c.push_back(p[i]);
            done[i] = true;
            i = p[i];
        }
        if (sz(c) > 1) cycles.push_back(c);
    }
    return cycles;
}

const int MAX_M = 1 << 23;
int dp[MAX_M];

int getZero() {
    dp[0] = 0;
    for (int mask = 1; mask < MAX_M; mask++) {
        int i = __builtin_ctz(mask);
        dp[mask] = dp[mask ^ (1 << i)] ^ a[i];
        if (dp[mask] == 0) return mask;
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mask = getZero();
    int first = -1;
    for (int i = 0; i < 23; i++) {
        if (mask >> i & 1) {
            if (first == -1) first = i;
            else operation(first, i);
        }
    }
    swap(0, first);
    auto cycles = getCycles(n);
    int m = 0;
    for (auto c : cycles) m += 3 * (sz(c) - 1);
    if (m <= 2500) {
        for (auto c : getCycles(n)) {
            for (int i = 1; i < sz(c); i++) {
                swap(c[i - 1], c[i]);
            }
        }
    } else {
        for (auto c : getCycles(n)) {
            int prev = 0;
            c.push_back(0);
            for (int i = 0; i < sz(c); i++) {
                swap(prev, c[i]);
                prev = c[i];
            }
        }
    }
    cout << sz(op) << '\n';
    for (auto [x, y] : op) {
        cout << x << ' ' << y << '\n';
    }
    
    return 0;
}