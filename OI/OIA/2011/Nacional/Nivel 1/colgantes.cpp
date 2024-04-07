#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("colgantes.in", "r", stdin);
	freopen("colgantes.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    const int C = 101;
    vector<int> cant(C, 0);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cant[p]++;
    }
    
    int w = 0, v = 0;
    for (int i = 0; i < C; i++) {
        int p = cant[i] / 2;
        w += 2 * p * i;
        v += p;
    }
    if (v == 0) {
        cout << "no se puede\n";
    } else {
        cout << w << ' ' << v << '\n';
    }
    
    return 0;
}
