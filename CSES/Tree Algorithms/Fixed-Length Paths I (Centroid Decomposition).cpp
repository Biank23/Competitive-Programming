#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 2e5 + 9;
 
vector<int> adj[MAX_N];
bitset<MAX_N> done;
int sz[MAX_N];
 
ll cnt1[MAX_N], cnt2[MAX_N];
int cnt1Size = 0, cnt2Size = 0, k;
 
int getSize(int u, int p = -1) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !done[v]) {
            sz[u] += getSize(v, u);
        }
    }
    return sz[u];
}
 
int findCentroid(int u, int size, int p = -1) {
    for (int v : adj[u]) {
        if (v != p && !done[v] && sz[v] > size / 2) {
            return findCentroid(v, size, u);
        }
    }
    return u;
}
 
void dfs(int u, int p = -1, int d = 1) {
    if (d > k) return;
    cnt2Size = max(cnt2Size, d);
    cnt2[d]++;
    
    for (int v : adj[u]) {
        if (v != p && !done[v]) {
            dfs(v, u, d+1);
        }
    }
}
 
ll res = 0;
 
void solve(int u, int d = 0) {
    int size = getSize(u);
    u = findCentroid(u, size);
    done[u] = true;
 
    cnt1Size = 0;
    cnt1[0] = 1;
    for (int v:adj[u]) {
        if (!done[v]) {
            cnt2Size = 0;
            dfs(v);
            for (int i = 0; i <= cnt2Size; i++) {
                res += cnt2[i] * cnt1[k - i];
            }
            for (int i = 0; i <= cnt2Size; i++) {
                cnt1[i] += cnt2[i];
                cnt2[i] = 0;
            }
            cnt1Size = max(cnt1Size, cnt2Size);
        }
    }
    
    for (int i = 0; i <= cnt1Size; i++) {
        cnt1[i] = 0;
    }
    
    for (int v:adj[u]) {
        if (!done[v]) {
            solve(v, d+1);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n >> k;
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(0);
    cout << res << '\n';
    
    return 0;
}