#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

struct Num {
    string n;
    friend bool operator<(Num a, Num b) {
        if (sz(a.n) != sz(b.n)) return sz(a.n) < sz(b.n);
        return a.n < b.n;
    }
    friend bool operator<=(Num a, Num b) {
        return !(b < a);
    }
    Num& append(int digit, int cant = 1) {
        n += string(cant, char('0' + digit));
        return *this;
    }
    friend istream &operator>>(istream &is, Num &a) {
        return is >> a.n;
    }
    size_t size() {
       return n.size();
    }
    Num& operator++() {
        int i = sz(n) - 1;
        while (n[i] == '9') {
            n[i] = 0, i--;
        }
        if (i >= 0) n[i]++;
        else n = "1" + n;
        return *this;
    }
};

Num solve(Num a, Num b) {
    int diff = max(sz(a) - sz(b), 0);
    Num c = b;
    c.append(0, diff);
    if (a < c) return c;
    b.append(9, diff);
    if (b <= a) return c.append(0);
    return ++a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 1; tt <= TT; tt++) {
        int n;
        cin >> n;
        vector<Num> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int cost = 0;
        for (int i = 1; i < n; i++) {
            int s = sz(a[i]);
            a[i] = solve(a[i - 1], a[i]);
            cost += sz(a[i]) - s;
        }
        cout << "Case #" << tt << ": " << cost << '\n';
    }
    
    return 0;
}
