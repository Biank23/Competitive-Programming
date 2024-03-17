#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ii = pair<int,int>;
using ll = long long;
using vll = vector<ll>;

const ll INF = 1e18;

void transpose(vector<vll> &v) {
    int n = sz(v), m = sz(v[0]);
    vector<vll> t(m, vll(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t[j][i] = v[i][j];
        }
    }
    v = t;
}

void applyRow(vector<vll> &v, auto f, int k) {
    for (int i = 0; i < sz(v); i++) {
        v[i] = f(v[i], k);
    }
}

vector<vll> applyMatrix(vector<vll> v, auto f, int a, int b) {
    for (int k : {a, b}) {
        applyRow(v, f, k);
        transpose(v);
    }
    return v;
}

struct Min {
    vll v;
    deque<int> dq;
    Min(vll &_v) : v(_v) {}
    void add(int i) {
        while (!dq.empty() && v[dq.back()] >= v[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    void erase(int i) {
        if (dq.front() == i) dq.pop_front();
    }
    ll getAns() {
        assert(!dq.empty());
        return v[dq.front()];
    }
};

struct Sum {
    vll v;
    ll sum;
    Sum(vll &_v) : v(_v), sum(0LL) {}
    void add(int i) {
        sum += v[i];
    }
    void erase(int i) {
        sum -= v[i];
    }
    ll getAns() {
        return sum;
    }
};

template<typename Window>
auto slidingWindow = [](vll v, int k) {
    int n = sz(v);
    Window w(v);
    vll ans;
    for (int i = 0; i < n; i++) {
        w.add(i);
        if (i >= k) w.erase(i - k);
        if (i >= k - 1) ans.push_back(w.getAns());
    }
    return ans;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m, n, a, b, c, d;
    cin >> m >> n >> a >> b >> c >> d;
    
    vector<vll> h(n, vll(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> h[i][j];
        }
    }
    
    auto sum1 = applyMatrix(h, slidingWindow<Sum>, a, b);
    auto sum2 = applyMatrix(h, slidingWindow<Sum>, c, d);
    vector<vll> mini = applyMatrix(sum2, slidingWindow<Min>, a - c - 1, b - d - 1);
    
    pair<ll, ii> ans = {0, {-1, -1}};
    for (int i = 0; i < sz(sum1); i++) {
        for (int j = 0; j < sz(sum1[i]); j++) {
            ans = max(ans, {sum1[i][j] - mini[i + 1][j + 1], {i,  j}});
        }
    }
    auto [x, y] = ans.second;
    cout << y + 1 << ' ' << x + 1 << '\n';
    ans = {INF, {n, m}};
    for (int i = x + 1; i < x + b - d; i++) {
        for (int j = y + 1; j < y + a - c; j++) {
            ans = min(ans, {sum2[i][j], {i, j}});
        }
    }
    tie(x, y) = ans.second;
    cout << y + 1 << ' ' << x + 1 << '\n';
    
    return 0;
}
