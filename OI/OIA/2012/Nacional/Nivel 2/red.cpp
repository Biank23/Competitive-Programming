#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 9;

int par[MAX_N];

void init() {
    for (int i = 0; i < MAX_N; i++) {
        par[i] = i;
    }
}

int find(int a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) par[a] = b;
}

int main() {
    freopen("red.in", "r", stdin);
	freopen("red.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    init();
    while (true) {
        char type;
        cin >> type;
        if (type == 'F') break;
        int a, b;
        cin >> a >> b;
        if (type == 'C') {
            unite(a, b);
        } else if (type == 'P') {
            if (find(a) == find(b)) cout << "S\n";
            else cout << "N\n";
        } else {
            assert(false);
        }
    }
    
    return 0;
}
