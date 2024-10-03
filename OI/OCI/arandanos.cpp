#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define forn(i,n) for(int i=0;i<int(n);i++)

#define fst first
#define snd second
#define pb push_back

using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 2e5+5;

vi adj[MAXN];
int c[MAXN], color;
int ans[MAXN], d[MAXN];

void dfs(int u, int dist, int p = -1) {
    d[u] = dist;
    for(int v : adj[u]) if (v != p) {
        dfs(v, dist + (c[v] == color), u);
    }
}

void findDiameter(int n) {
    ii maxi = {d[0], 0};
    forn(t,3){
        dfs(maxi.snd, c[maxi.snd] == color);
        maxi = {d[maxi.snd], maxi.snd};
        forn(i,n){
            maxi = max(maxi, {d[i], i});
            ans[i] = max(ans[i], d[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    forn(i,n){
        cin >> c[i];
        --c[i];
    }
    forn(i,n-1){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    forn(i,k){
        color = i;
        findDiameter(n);
    }
    int q;
    cin >> q;
    forn(i,q){
        int u;
        cin >> u;
        cout << ans[u] << '\n';
    }
    
    return 0;
}