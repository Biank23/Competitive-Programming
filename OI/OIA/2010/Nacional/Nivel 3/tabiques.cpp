#include <bits/stdc++.h>
#pragma GCC optimize ("03", "unroll-loops")
using namespace std;

const int MAX_N = 4000;

vector<int> d;
bitset<MAX_N * MAX_N> vis;
char bloq[MAX_N * MAX_N];
const int MAX_Q = 2 * MAX_N;

int q[MAX_Q];

int front = 0, back = 0;

int sz() {
  int s = back - front;
  if (s < 0) s += MAX_Q;
  return s;
}

void nxt(int &x) {
  if (++x == MAX_Q) x = 0;
}

int bfs(int target) {
  q[back] = 0;
  nxt(back);
  vis[0] = true;
  for (int dist = 0; front != back; dist++) {
    for (int s = sz(); s > 0; s--) {
      int u = q[front];
      nxt(front);
      if (u == target) return dist;
      for (int i = 0; i < 4; i++) {
        if (bloq[u] >> i & 1) continue;
        int v = u + d[i];
        if (!vis[v]) {
          q[back] = v;
          nxt(back);
          vis[v] = true;
        }
      }
    }
  }
  return -1;
}

int main() {
    freopen("tabiques.in", "r", stdin);
    freopen("tabiques.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int h, w, n;
    cin >> h >> w >> n;
    d = {-w, w, -1, 1};
    
    for (int i = 0; i < n; i++) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        if(x1 < x0) swap(x0, x1);
        if(y1 < y0) swap(y0, y1);
        int u = x0 * w + y0;
        if (x0 == x1) {
            for (int y = y0; y < y1; y++, u++) {
                bloq[u] |= 1, bloq[u - w] |= 2;
            }
        } else if (y0 == y1) {
            for (int x = x0; x < x1; x++, u += w) {
                bloq[u] |= 4, bloq[u - 1] |= 8;
            }
        } else assert(false);
    }
    int u = (h - 1) * w;
    for (int y = 0; y < w; y++, u++) {
        bloq[y] |= 1, bloq[u] |= 2;
    }
    u = 0;
    for (int x = 0; x < h; x++, u += w) {
        bloq[u] |= 4, bloq[u + w - 1] |= 8;
    }
    int ans = bfs(h * w - 1);
    if (ans == -1) cout << "imposible\n";
    else cout << ans << '\n';
    
    return 0;
}