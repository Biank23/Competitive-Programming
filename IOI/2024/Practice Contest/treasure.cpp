#include <bits/stdc++.h>
#include "treasure.h"

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

const int LIMIT = 2 * (5e8 + 1);

vector<int> encode(vector<pair<int, int>> P) {
    int n = sz(P);
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        tie(X[i], Y[i]) = P[i];
    }
    sort(all(Y));
    vector<int> S;
    for (int i = 0; i < n; i++) {
        S.push_back(2 * X[i]);
        S.push_back(2 * Y[i] + 1);
    }
    sort(all(P));
    int pref = LIMIT;
    for (int i = 0; i < n; i++) {
        pref += int(lower_bound(all(Y), P[i].second) - begin(Y));
        S.push_back(pref);
    }
    return S;
}

vector<pair<int, int>> decode(vector<int> S) {
    int n = sz(S) / 3;
    vector<int> X, Y, pref = {LIMIT};
    for (int i = 0; i < sz(S); i++) {
        if (S[i] >= LIMIT) {
            pref.push_back(S[i]);
        } else if (S[i] % 2 == 0) {
            X.push_back(S[i] / 2);
        } else {
            Y.push_back(S[i] / 2);
        }
    }
    sort(all(X)), sort(all(Y)), sort(all(pref));
    vector<pair<int, int>> P(n);
    for (int i = 0; i < n; i++) {
        P[i] = {X[i], Y[pref[i + 1] - pref[i]]};
    }
    return P;
}