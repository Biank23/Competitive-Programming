#include <bits/stdc++.h>

using namespace std;

int medir(string cad);

#define sz(x) int(x.size())

string merge(string &a, string &b) {
    string c = "";
    int i = 0, j = 0;
    while (i < sz(a) || j < sz(b)) {
        if (i >= sz(a) || (j < sz(b) && medir(c + b[j] + a.substr(i)))) {
            c += b[j];
            j++;
        } else {
            c += a[i];
            i++;
        }
    }
    return c;
}

string secuenciar(int N, string s) {
    int m = sz(s);
    int tot = N;
    auto cmp = [](const string &a, const string &b) {
        return sz(a) > sz(b);
    };
    priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < m - 1; i++) {
        int lo = 0; //medir("") = true
        int hi = tot + 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (medir(string(mid, s[i]))) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        pq.push(string(lo, s[i]));
        tot -= lo;
    }
    pq.push(string(tot, s.back()));
    if (s == "AC") return string(N - tot, 'A') + string(tot, 'C');
    while (sz(pq) >= 2) {
        string a = pq.top(); pq.pop();
        string b = pq.top(); pq.pop();
        pq.push(merge(a, b));
    }
    return pq.top();
}
