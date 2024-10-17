#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ii = pair<ll, ll>;
 
ii operator+(ii a, ii b) {
    return {a.first + b.first, a.second + b.second};
}
 
const ll UNKNOWN = 1e9 + 7;
 
ii solve(pair<ii, ll> ec1, pair<ii, ll> ec2) {
    auto [v1, c] = ec1; auto [a, b] = v1;
    auto [v2, f] = ec2; auto [d, e] = v2;
    ll y = (a * f - d * c) / (a * e - d * b);
    ll x = a != 0 ? (c - b * y) / a : (f - e * y) / d;
    return {x, y};
}
 
int main() {
    freopen("ladrillos.in", "r", stdin);
    freopen("ladrillos.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<ll> v(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        string val;
        cin >> val;
        if (val == "*") {
            v[i] = UNKNOWN;
        } else {
            v[i] = stoll(val);
            count++;
        }
    }
    if (count == 0) {
        v[0] = 1;
        if (1 < n) v[1] = 1;
        for (int i = 2; i < n; i++) {
            v[i] = v[i - 1] + v[i - 2];
        }
    }
    if (count == 1) {
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] != UNKNOWN) pos = i;
        }
        if (pos != 0) v[pos - 1] = 1;
        else if (pos != n - 1) v[pos + 1] = 1;
        for (int i = pos + 1; i < n; i++) {
            if (v[i] == UNKNOWN) v[i] = v[i - 1] + v[i - 2];
        }
        for (int i = pos - 1; i >= 0; i--) {
            if (v[i] == UNKNOWN) v[i] = v[i + 2] - v[i + 1];
        }
    }
    if (count < 2) {
        for (int i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return 0;
    }
    vector<ii> c(n);
    c[0] = {1, 0}, c[1] = {0, 1};
    for (int i = 2; i < n; i++) {
        c[i] = c[i - 1] + c[i - 2];
    }
    pair<ii, ll> ec[2];
    int j = 0;
    for (int i = 0; i < n && j < 2; i++) {
        if (v[i] != UNKNOWN) {
            ec[j] = {c[i], v[i]};
            j++;
        }
    }
    auto [x, y] = solve(ec[0], ec[1]);
    for (auto [a, b] : c) {
        cout << a * x + b * y << ' ';
    }
    cout << '\n';
    
    return 0;
}