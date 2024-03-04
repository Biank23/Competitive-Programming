#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int x, n;
	cin >> x >> n;
	
	priority_queue<ll, vector<ll>, greater<ll>> pq;
    auto pop = [&]() {
        ll v = pq.top();
        pq.pop();
        return v;
    };
    
	for (int i = 0; i < n; i++) {
		ll d;
		cin >> d;
		pq.push(d);
	}
    
	ll res = 0;
	while (ssize(pq) >= 2) {
        ll stick = pop() + pop();
		pq.push(stick);
		res += stick;
	}
	cout << res << '\n';
	
	return 0;
}