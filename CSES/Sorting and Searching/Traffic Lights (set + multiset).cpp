#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int x, n;
	cin >> x >> n;
 
	set<int> lights{0, x};
	multiset<int> passages{x};
 
	for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        auto it = lights.upper_bound(p);
        int l = *prev(it), r = *it;
        passages.erase(passages.find(r - l));
        lights.insert(p);
        passages.insert(r - p);
        passages.insert(p - l);
        cout << *passages.rbegin() << ' ';
    }
    cout << '\n';
    
    return 0;
}
