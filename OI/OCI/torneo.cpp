#include <bits/stdc++.h>
#include "torneo.h"

using namespace std;

using ii = pair<int, int>;

const int MAX_N = 1000;
const int NEUTR = 0;

int op(int i, int j) {
    if (i == NEUTR) return j;
    if (j == NEUTR) return i;
    return ganador(i, j) ? i : j;
}

int st[2 * MAX_N], n;

void update(int i, int v) {
    st[i += n] = v;
    while (i /= 2) {
        st[i] = op(st[2 * i], st[2 * i + 1]);
    }
}

ii top_2_inversiones(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) {
        st[i + n] = i + 1;
    }
    for (int i = n - 1; i > 0; i--) {
        st[i] = op(st[2 * i], st[2 * i + 1];
    }
    int maxi = st[1];
    update(maxi - 1, NEUTR);
    int sndMaxi = st[1];
    return {maxi, sndMaxi};
}
