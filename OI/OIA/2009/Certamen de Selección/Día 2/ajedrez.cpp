#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;
const int INF = 1e9;

const int MOVES = 16;

int dx[MOVES] =   {1, 1, -1, -1, 0, 1, 0, -1, 2, -2, 2, -2, 1, -1, 1, -1};
int dy[MOVES] =   {1, -1, -1, 1, 1, 0, -1, 0, 1, 1, -1, -1, 2, 2, -2, -2};
int cost[MOVES] = {2, 2,   2, 2, 3, 3, 3, 3,  1, 1,  1,  1, 1, 1,  1,  1};

const int MOVE_STATES = 9;

bitset<MAX_N> g[MAX_N];
const int TOT_STATES = MAX_N * MAX_N * 3 * MOVE_STATES;
int dist[TOT_STATES], jug[TOT_STATES];

pair<int, int> bfs(int n) {
    for (int i = 0; i < TOT_STATES; i++) {
        dist[i] = INF;
    }
    vector<vector<int>> q(4);
    int idx = 0;
    q[idx].push_back(8);
    dist[8] = 0;
    int currDist = 0;
    while (!q[0].empty() || !q[1].empty() || !q[2].empty() || !q[3].empty()) {
        while (!q[idx].empty()) {
            int state = q[idx].back();
            int x = state / (MAX_N * 3 * MOVE_STATES);
            int y = (state / (3 * MOVE_STATES)) % MAX_N;
            int c = (state / MOVE_STATES) % 3;
            int move = state % 9;
            q[idx].pop_back();
            if (dist[state] < currDist) {
                continue;
            }
            if (x == n - 1 && y == n - 1) {
                return {dist[state], jug[state]};
            }
            for (int i = 0; i < MOVES; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || g[nx][ny]) {
                    continue;
                }
                int nc = 1;
                int weight = 0;
                if (cost[i] == 1 || i != move) {
                    weight = cost[i];
                }
                if (cost[i] == cost[move]) {
                    nc = c + (weight != 0);
                }
                if (nc < 3) {
                    int moveState = min(i, 8);
                    int nstate = nx * MAX_N * 3 * MOVE_STATES + ny * 3 * MOVE_STATES + nc * MOVE_STATES + moveState;
                    int ndist = dist[state] + weight;
                    int njug = jug[state] + (weight != 0);
                    if (dist[nstate] > ndist) {
                        dist[nstate] = ndist;
                        jug[nstate] = njug;
                        q[(idx + weight) & 3].push_back(nstate);
                    }
                }
            }
        }
        currDist++;
        idx = (idx + 1) & 3;
    }
    assert(false);
}

int main() {
    freopen("ajedrez.in", "r", stdin);
	freopen("ajedrez.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b, --c, --d;
        while (a != c || b != d) {
            g[a][b] = true;
            if (a < c) a++;
            else if (a > c) a--;
            if (b < d) b++;
            else if (b > d) b--;
        }
        g[a][b] = true;
    }
    
    pair<int, int> ans = bfs(n);
    cout << ans.second << ' ' << ans.first << '\n';
    
    return 0;
}
