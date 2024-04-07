#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void print(vector<int> &v) {
    for (int &x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    freopen("truco.in", "r", stdin);
	freopen("truco.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    indexed_set<int> jugadores;
    for (int i = 1; i <= n; i++) {
        jugadores.insert(i);
    }
    const int C = 40;
    bool esRey[C];
    for (int i = 0; i < C; i++) {
        int num;
        char palo;
        cin >> num >> palo;
        esRey[i] = num == 12;
    }
    
    int target = n / 2;
    int i = 0;
    int pos = 0;
    vector<int> equipo1, equipo2;
    while (n > target) {
        if (esRey[i]) {
            int jug = *jugadores.find_by_order(pos);
            pos--;
            equipo1.push_back(jug);
            jugadores.erase(jug);
            n--;
        }
        i++;
        if (++pos == n) {
            pos = 0;
        }
    }
    for (int jug : jugadores) {
        equipo2.push_back(jug);
    }
    
    print(equipo1);
    print(equipo2);
    
    return 0;
}
