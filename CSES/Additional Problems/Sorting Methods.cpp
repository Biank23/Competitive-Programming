#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ll = long long;
using vi = vector<int>;
 
const int MAX_N = 2e5 + 9;
 
int ft[MAX_N];
 
inline int lsb(int i) {
    return i & (-i);
}
 
void update(int i, int v) {
    ++i;
    while (i < MAX_N) {
        ft[i] += v;
        i += lsb(i);
    }
}
 
int query(int i) { //[0, i)
    int s = 0;
    while (i > 0) {
        s += ft[i];
        i -= lsb(i);
    }
    return s;
}
 
ll inversions(vi v) {
    int n = ssize(v);
    vi p(n);
    for (int i = 0; i < n; i++) {
        update(i, 1);
        p[i] = i;
    }
    sort(all(p), [&](const int &a, const int &b) {
        return v[a] < v[b];
    });
    ll res = 0;
    for (int i : p) {
        res += query(i);
        update(i, -1);
    }
    return res;
}
 
int cycleSort(vi v) {
    for (int &x : v) x--;
    int n = ssize(v);
    vi vis(n, false);
    int res = n;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            res--;
            for (int j = i; !vis[j]; j = v[j]) {
                vis[j] = true;
            }
        }
    }
    return res;
}
 
int lis(vi v) {
    int n = ssize(v);
    vi lis;
    int res = n;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(lis), v[i]);
        if (it == end(lis)) {
            lis.push_back(v[i]);
            res--;
        } else {
            *it = v[i];
        }
    }
    return res;
}
 
int greedy(vi v) {
    int n = ssize(v);
    int res = n;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == res) res--;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    cout << inversions(v) << ' ' << cycleSort(v) << ' ' << lis(v) << ' ' << greedy(v) << '\n';
    
    return 0;
}