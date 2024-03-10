#include <bits/stdc++.h>
 
using namespace std;
 
struct Line {
    int m, b;
    Line() : m(0), b(0) {}
    Line(int _m, int _b) : m(_m), b(_b) {}
    Line& operator+=(Line o) {
        m += o.m, b += o.b;
        return *this;
    }
    Line& operator-=(Line o) {
        m -= o.m, b -= o.b;
        return *this;
    }
    int operator()(int x){
        return m * x + b;
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m, n;
    cin >> m >> n;
    
    vector<vector<Line>> c(m + 2, vector<Line>(n + 2));
    auto add = [&](int i0, int j0, int i1, int j1, Line L) {
        c[i0][j0] += L, c[i0][j1 + 1] -= L;
        c[i1 + 1][j0] -= L, c[i1 + 1][j1 + 1] += L;
    };
    
    vector<int> v(n, 0);
    auto getVal = [&](int i) {
        if (i == -1 || i == n) return -1;
        return v[i];
    };
    
    for (int j = 0; j < m; j++) {
        string s;
        cin >> s;
        
        for (int i = 0; i < n; i++) {
            ++v[i];
            if (s[i] == '*') v[i] = 0;
        }
        
        vector<int> l(n);
        for (int i = 0; i < n; i++) {
            l[i] = i - 1;
            while (getVal(l[i]) >= v[i]) {
                l[i] = l[l[i]];
            }
        }
    
        vector<int> r(n);
        for (int i = n - 1; i >= 0; i--) {
            r[i] = i + 1;
            while (getVal(r[i]) > v[i]) {
                r[i] = r[r[i]];
            }
        }
        
        for (int i = 0; i < n; i++) {
            int length = r[i] - l[i] - 1;
            add(1, 1, v[i], length, {1, 0});
            add(1, r[i] - i, v[i], length, {-1, r[i] - i});
            add(1, i - l[i], v[i], length, {-1, i - l[i]});
        }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] += c[i][j - 1];
            c[i][j] += c[i - 1][j];
            c[i][j] -= c[i - 1][j - 1];
            cout << c[i][j](j) << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
