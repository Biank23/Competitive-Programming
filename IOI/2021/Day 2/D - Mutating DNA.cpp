#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int MAX_M = 6;
const string s1 = "ACTACT";
const string s2 = "CAATTC";

vector<int> p[MAX_M];

void init(string a, string b) {
    int n = sz(a);
    for (int i = 0; i < MAX_M; i++) {
        p[i].assign(n + 1, 0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_M; j++) {
            p[j][i + 1] = p[j][i] + (a[i] == s1[j] && b[i] == s2[j]);
        }
    }
}

int get_distance(int x, int y) {
    int cant[MAX_M];
    for (int i=0; i < MAX_M; i++) {
        cant[i] = p[i][y+1] - p[i][x];
    }
    int ans = 0;
    for (int i = 0; i < MAX_M; i += 2) {
        int moves = min(cant[i], cant[i + 1]);
        cant[i] -= moves;
        cant[i + 1] -= moves;
        ans += moves;
    }
    for (int i = 0; i < MAX_M - 2; i++) {
        if (cant[i] != cant[i + 2]) return -1;
    }
    ans += 2 * cant[0] + 2 * cant[1];
    return ans;
}
