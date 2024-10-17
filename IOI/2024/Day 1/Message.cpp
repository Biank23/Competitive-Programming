#include <bits/stdc++.h>

using namespace std;

using vb = vector<bool>;

const int N = 1025, L = 31, Q = 66;

vb send_packet(vb A);

void send_message(vb M, vb C) {
    vector<vb> R(Q, vb(L, 0));
    M.resize(N, M.back() ^ 1);
    int k = 0;
    for (int i = 0; i < L; i++) if (C[i] == 0) {
        int c = 1;
        while (C[(i + c) % 31] == 1) c++;
        R[c - 1][i] = 1;
        for (int j = c; j < Q; j++) R[j][i] = M[k++];
    }
    for (int i = 0; i < Q; i++) send_packet(R[i]);
}

vb receive_message(vector<vb> R) {
    vector<int> f(L);
    for (int i = 0; i < L; i++) {
        int c = 1;
        for (int j = 0; j < Q; j++) {
            if (R[j][i] == 1) break;
            c++;
        }
        f[i] = (i + c) % 31;
    }
    vb M(N);
    int k = 0;
    for (int i = 0; i < L; i++) {
        bool flag = true;
        int p = i;
        for (int t = 0; t < 16; t++) {
            p = f[p], flag &= (p == i) == (t == 15);
        }
        if (!flag) continue;
        flag = false;
        for (int j = 0; j < Q; j++) {
            if (flag) M[k++] = R[j][i];
            else flag = R[j][i];
        }
    }
    bool b = M.back();
    while (M.back() == b) M.pop_back();
    return M;
}