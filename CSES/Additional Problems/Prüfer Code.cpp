#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
int deg[MAX_N], a[MAX_N];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
    cin >> n;
	for (int i = 0; i < n - 2; i++) {
		cin >> a[i];
		a[i]--;
		deg[a[i]]++;
	}
    
    int j = 0;
    while (deg[j] != 0) j++;
    int leaf = j++;
    for (int i = 0; i < n - 2; i++) {
        cout << a[i] + 1 << ' ' << leaf + 1 << '\n';
        deg[a[i]]--;
        if (deg[a[i]] == 0 && a[i] < j) {
            leaf = a[i];
        } else {
            while (deg[j] != 0) j++;
            leaf = j++;
        }
    }
    cout << leaf + 1 << ' ' << n << '\n';
	
	return 0;
}