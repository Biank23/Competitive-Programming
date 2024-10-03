#include <bits/stdc++.h>
#include "skolib.h"

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;
using ii = pair<int, int>;

const vi dx = {1, 2, -1, -2, 1, 2, -1, -2};
const vi dy = {-2, -1, 2, 1, 2, 1, -2, -1};

const int INF = 1e9;
const int LIMIT = 1e8;

int n;

vector<vi> bfs(vector<ii> source) {
    vector<vi> dist(n, vi(n, INF));
    queue<ii> q;
    for (auto [x, y] : source) {
        dist[x][y] = 0;
        q.emplace(x, y);
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    return dist;
}

vector<ii> candidates, sources;

void filter(int x, int y) {
    sources.emplace_back(x, y);
    vector<vi> dist = bfs({{x, y}});
    int res = pytanie(x + 1, y + 1);
    vector<ii> new_candidates;
    for (auto [i, j] : candidates) {
        if (dist[i][j] == res) new_candidates.emplace_back(i, j);
    }
    candidates = new_candidates;
}

int main() {
    n = daj_n();
    candidates.reserve(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            candidates.emplace_back(i, j);
        }
    }
    filter(0, 0);
    int x = 0, y = n - 1;
    while (sz(candidates) > 1) {
        filter(x, y);
        long long cost = 1LL * n * n * sz(candidates);
        if (cost > LIMIT) {
            vector<vi> dist = bfs(sources);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[x][y] < dist[i][j]) x = i, y = j;
                }
            }
        } else {
            int mini = sz(candidates);
            vector<vector<map<int, int>>> freq(n, vector<map<int, int>>(n));
            for (auto c : candidates) {
                vector<vi> dist = bfs({c});
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        freq[i][j][dist[i][j]]++;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int maxi = 0;
                    for (auto [_, cant] : freq[i][j]) maxi = max(maxi, cant);
                    if (maxi < mini) {
                        mini = maxi;
                        x = i, y = j;
                    }
                }
            }
        }
    }
    tie(x, y) = candidates[0];
    odpowiedz(x + 1, y + 1);
}
