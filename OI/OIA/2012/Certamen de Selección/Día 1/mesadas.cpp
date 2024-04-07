#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ii = pair<int, int>;
 
int main() {
	freopen("mesadas.in", "r", stdin);
	freopen("mesadas.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
    int n;
    cin >> n;
    vector<ii> v(n);
    for (auto &[a, b] : v) {
        cin >> a >> b;
		if (a > b) swap(a, b);
    }
    sort(all(v), greater<ii>());
    vector<int> lis;
    for (auto [_, x] : v) {
        auto it = lower_bound(all(lis), x);
        if (it == end(lis)) lis.push_back(x);
        else *it = x; 
    }
    cout << sz(lis) << '\n';
    
    return 0;
}
