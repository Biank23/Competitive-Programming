#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ii = pair<int, int>;

const int TEMP_MAX = 61;
const int TEMP_MIN = -51;
const int MAX_N = TEMP_MAX - TEMP_MIN + 5;

int ft[MAX_N];

void update(int i, int v) {
    for (++i; i < MAX_N; i += i&-i) {
        ft[i] += v;
    }
}

int query(int i) {
    int s = 0;
    for (++i; i > 0; i -= i&-i) {
        s += ft[i];
    }
    return s;
}

using ti = tuple<int, int, int>;

int main() {
    freopen("clima.in", "r", stdin);
	freopen("clima.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    map<ii, int> count;
    vector<ti> stations(n);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        int tmin = TEMP_MAX, tmax = TEMP_MIN;
        for (int j = 0; j < s; j++) {
            int m, M;
            cin >> m >> M;
            tmin = min(tmin, m);
            tmax = max(tmax, M);
        }
        tmin -= TEMP_MIN, tmax -= TEMP_MIN;
        count[{tmin, tmax}]++;
        stations[i] = {-tmin, tmax, i + 1};
    }
    sort(all(stations));
    int i = 0;
    vector<ti> ans(n);
    while (i < n) {
        auto [tmin, tmax, idx] = stations[i];
        tmin *= -1;
        int a = query(tmax);
        int r = count[{tmin, tmax}];
        int b = n - a - r;
        update(tmax, r);
        while (r--) {
            ans[i] = {-a, get<2>(stations[i]), b};
            i++;
        }
    }
    sort(all(ans));
    i = 0;
    while (i < n && get<0>(ans[i]) == get<0>(ans[0])) {
        auto [a, idx, b] = ans[i];
        cout << idx << ' ' << b << '\n';
        i++;
    }
    
    return 0;
}
