#include <bits/stdc++.h>
#include "secret.h"

using namespace std;
 
const int MAX_N = 1000;
const int MAX_H = 10;
 
int val[MAX_H][MAX_N], n;
 
void build(int l, int r, int a[], int h) {
    int m = (l + r) / 2;
    val[h][m] = a[m];
    if (l == r) return;
    val[h][m + 1] = a[m + 1];
    for (int i = m + 2; i <= r; i++) {
        val[h][i] = Secret(val[h][i - 1], a[i]);
    }
    for (int i = m - 1; i >= l; i--) {
        val[h][i] = Secret(a[i], val[h][i + 1]);
    }
    build(l, m, a, h + 1);
    build(m + 1, r, a, h + 1);
}
 
void Init(int N, int a[]) {
    n = N;
    build(0, n - 1, a, 0);
}
 
int solve(int l, int r, int a, int b, int h) {
    if (l == r) return val[h][a];
    int m = (l + r) / 2;
    if (b <= m) return solve(l, m, a, b, h + 1);
    if (a > m) return solve(m + 1, r, a, b, h + 1);
    return Secret(val[h][a], val[h][b]);
}
 
int Query(int L, int R) {
    return solve(0, n - 1, L, R, 0);
}