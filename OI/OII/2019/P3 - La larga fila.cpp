#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n,k,q;
    cin >> n >> k >> q;
    map<string, int> m;
    list<int> l;
    vector<list<int>::iterator> p(n);
    for (int i = 0; i < n; i++) {
        string name;
        int s;
        cin >> name >> s;
        m[name] = i;
        p[i] = l.insert(l.end(), s - 1);
    }
    vector<vector<int>> a(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    while (q--) {
        int t;
        string x;
        cin >> t >> x;
        if (t == 1) {
            string y;
            cin >> y;
            int s = *p[m[x]];
            l.erase(p[m[x]]);
            p[m[x]] = l.insert(p[m[y]], s);
        } else if (t == 2) {
            int s;
            cin >> s;
            *p[m[x]] = s - 1;
        } else {
            ll res = 0;
            int s = *p[m[x]];
            int count = 0;
            auto it = p[m[x]];
            while (it != l.begin() && count < 31) {
                --it;
                res += a[s][*it] >> count;
                count++;
            }
            count = 0;
            it = next(p[m[x]]);
            while (it != l.end() && count < 31) {
                res += a[s][*it] >> count;
                it++;
                count++;
            }
            cout << res << '\n';
        }
    }
    
    return 0;
}