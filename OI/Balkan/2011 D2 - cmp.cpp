#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 4095;
 
vector<int> offset(6);
 
void bit_set(int addr);
int bit_get(int addr);
 
void remember(int n) {
    offset[0] = 1;
    for (int i = 0; i < 5; i++) {
        offset[i + 1] = offset[i] + (MAX_N >> (2 * i)) + 1;
    }
    for (int i = 0; i < 6; i++) {
        bit_set(offset[i] + (n >> (2 * i)));
    }
}
 
int compare(int b) {
    int l = -1, r = 6;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (bit_get(offset[m] + (b >> (2 * m)))) {
            r = m;
        } else {
            l = m;
        }
    }
    if (l == -1) return 0;
    int digit = (b >> (2 * l)) & 3;
    if (digit == 0) return -1;
    if (digit == 3) return 1;
    if (digit == 1) {
        if (bit_get(offset[l] + 4 * (b >> (2 * r)))) return 1;
        else return -1;
    }
    if (digit == 2) {
        if (bit_get(offset[l] + 4 * (b >> (2 * r)) + 3)) return -1;
        else return 1;
    }
    assert(false);
}