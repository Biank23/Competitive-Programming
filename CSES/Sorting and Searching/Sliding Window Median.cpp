#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    multiset<int> l, r;
    
    auto balance = [&]() {
        if (ssize(l) > ssize(r) + 1) {
            r.insert(*rbegin(l));
            l.erase(prev(end(l)));
        }
        if (ssize(r) > ssize(l)) {
            l.insert(*begin(r));
            r.erase(begin(r));
        }
    };
    
    auto getMedian = [&]() {
        return *rbegin(l);
    };
    
    auto add = [&](int x) {
        if (empty(l) || x < getMedian()) {
            l.insert(x);
        } else {
            r.insert(x);
        }
        balance();
    };
    
    auto erase = [&](int x) {
        auto it = r.find(x);
        if (it != end(r)) {
            r.erase(it);
        } else {
            it = l.find(x);
            l.erase(it);
        }
        balance();
    };
    
    for (int i = 0; i < n; i++) {
        add(a[i]);
        if (i >= k) {
            erase(a[i - k]);
        }
        if (i >= k - 1) {
            cout << getMedian() << ' ';
        }
    }
    cout << '\n';
    
    return 0;
}