#include "vision.h"
#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define pb push_back

using vi = vector<int>;

pair<vi, vi> process(vector<vi> diag) {
    int n = sz(diag);
    vi one(n), two(n);
    for (int i = 0; i < n; i++) {
        assert(!diag.empty());
        one[i] = add_or(diag[i]);
        two[i] = add_and({one[i], add_not(add_xor(diag[i]))});
    }
    return {one, two};
}

int join(vi one, vi two, int k) {
    if (k == 0) return add_and({0, add_not(0)});
    vi instructions = two;
    int n = sz(one);
    for (int i = 0; i < n - k; i++) {
        vi group;
        for (int j = i; j <= i + k; j++) {
            group.pb(one[j]);
        }
        instructions.pb(add_and({add_or(group), add_not(add_xor(group))}));
    }
    return add_or(instructions);
}

void construct_network(int H, int W, int K) {
    int n = H + W - 1;
    vector<vi> diag[2];
    for (int i = 0; i < 2; i++) {
        diag[i].resize(n);
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            diag[0][i + j].pb(i * W + j);
            diag[1][i - j + W - 1].pb(i * W + j);
        }
    }
    vi one[2], two[2];
    for (int i = 0; i < 2; i++) {
        tie(one[i], two[i]) = process(diag[i]);
    }
    int ans[2];
    for (int i = 0; i < 2; i++) {
        vi instructions;
        for (int j = 0; j < 2; j++) instructions.pb(join(one[j], two[j], K - i));
        ans[i] = add_and(instructions);
    }
    add_and({ans[0], add_not(ans[1])});
}
