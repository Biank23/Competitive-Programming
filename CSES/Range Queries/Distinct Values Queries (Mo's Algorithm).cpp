#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
const int BLOCK_SIZE = 450;
 
struct Query {
    int l, r, idx;
    bool operator<(const Query &o) {
        if (l / BLOCK_SIZE != o.l / BLOCK_SIZE) {
            return l < o.l;
        }
        if (l / BLOCK_SIZE & 1) {
            return r < o.r;
        }
        return r > o.r;
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    vector<int> vals(all(x));
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    
    for (int i = 0; i < n; i++) {
        x[i] = int(lower_bound(all(vals), x[i]) - begin(vals));
    }
    
    vector<Query> v(q);
    for (int i = 0; i < q; i++) {
        cin >> v[i].l >> v[i].r;
        --v[i].l, --v[i].r, v[i].idx = i;
    }
    sort(all(v));
    
    vector<int> freq(n, 0);
    int distinctValues = 0;
    
    auto add = [&](int i) {
        freq[x[i]]++;
        if (freq[x[i]] == 1) {
            distinctValues++;
        }
    };
    
    auto erase = [&](int i) {
        freq[x[i]]--;
        if (freq[x[i]] == 0) {
            distinctValues--;
        }
    };
    
    vector<int> res(q);
    int curL = 0, curR = -1;
    for (auto [l, r, idx] : v) {
        while (l < curL) {
            add(--curL);
        }
        while (r > curR) {
            add(++curR);
        }
        while (l > curL) {
            erase(curL++);
        }
        while (r < curR) {
            erase(curR--);
        }
        res[idx] = distinctValues;
    }
    
    for (int i = 0; i < q; i++) {
        cout << res[i] << '\n';
    }
    
    return 0;
}