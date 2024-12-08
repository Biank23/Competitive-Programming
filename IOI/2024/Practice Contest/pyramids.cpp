#include <bits/stdc++.h>
#include "pyramids.h"

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

vector<ll> buildPref(vector<int> &v) {
    int n = sz(v);
    vector<ll> pref(n + 1);
    pref[0] = 0LL;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }
    return pref;
}

vector<ll> prefA, prefB;

void init(vector<int> A, vector<int> B) {
    prefA = buildPref(A), prefB = buildPref(B);
}

bool can_transform(int L, int R, int X, int Y) {
    return prefA[R + 1] - prefA[L] == prefB[Y + 1] - prefB[X];
}