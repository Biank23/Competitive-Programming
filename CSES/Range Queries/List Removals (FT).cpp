#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1<<19;
 
int ft[MAX_N], v[MAX_N];
 
inline int lsb(int i) {
    return i & (-i);
}

void update(int i, int v){
    for(++i; i < MAX_N; i += lsb(i)) {
        ft[i] += v;
    }
}
 
int search(int s) {
    int x = 0;
    for (int d = MAX_N; d /= 2;) {
        if (ft[x | d] < s) {
            x |= d;
            s -= ft[x];
        }
    }
    return x;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
    cin >> n;
	for (int i = 0; i < n; i++) {
	    cin >> v[i];
	    update(i, 1);
	}
	for (int i = 0; i < n; i++) {
	    int x;
        cin >> x;
	    int p = search(x);
	    update(p, -1);
	    cout << v[p] << ' ';
	}
	
	return 0;
}