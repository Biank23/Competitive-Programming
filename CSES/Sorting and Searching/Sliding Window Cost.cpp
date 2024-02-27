#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
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
    ll leftSum = 0, rightSum = 0;
    
    auto balance = [&]() {
        if (ssize(l) > ssize(r) + 1) {
            int x = *rbegin(l);
            r.insert(x);
            rightSum += x;
            leftSum -= x;
            l.erase(prev(end(l)));
        }
        if (ssize(r) > ssize(l)) {
            int x = *begin(r);
            l.insert(x);
            leftSum += x;
            rightSum -= x;
            r.erase(begin(r));
        }
    };
    
    auto getMedian = [&]() {
        return *rbegin(l);
    };
    
    auto add = [&](int x) {
        if (empty(l) || x < getMedian()) {
            l.insert(x);
            leftSum += x;
        } else {
            r.insert(x);
            rightSum += x;
        }
        balance();
    };
    
    auto erase = [&](int x) {
        auto it = r.find(x);
        if (it != end(r)) {
            rightSum -= x;
            r.erase(it);
        } else {
            leftSum -= x;
            it = l.find(x);
            l.erase(it);
        }
        balance();
    };
    
    auto getCost = [&]() {
        return rightSum - ssize(r) * getMedian() +
               ssize(l) * getMedian() - leftSum;
    };
    
    for (int i = 0; i < n; i++) {
        add(a[i]);
        if (i >= k) {
            erase(a[i - k]);
        }
        if (i >= k - 1) {
            cout << getCost() << ' ';
        }
    }
    cout << '\n';
    
    return 0;
}