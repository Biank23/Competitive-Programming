#include <bits/stdc++.h>
#include "machine.h"

using namespace std;

vector<int> find_permutation(int N) {
    vector<int> A(N);
    for (int i = 1; i < N; i++) A[i - 1] = i;
    A[N - 1] = N + 2;
    vector<int> B = use_machine(A);
    for (int X = 0; X < 256; X++) {
        vector<int> cnt(N, 0);
        vector<int> P(N, 0);
        bool flag = true;
        for (int i = 0; i < N; i++) {
            int AP = B[i] ^ X;
            if (1 <= AP && AP < N) P[i] = AP - 1;
            else if (AP == N + 2) P[i] = N - 1;
            else flag = false;
            if (++cnt[P[i]] != 1) flag = false;
        }
        if (flag) return P;
    }
    assert(false);
}