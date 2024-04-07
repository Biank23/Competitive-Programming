#include <bits/stdc++.h>

using namespace std;

inline int ceilDiv(int a, int b) {
    return (a + b - 1) / b;
}

long long zetadieta(int C, int P, int G) {
    return ceilDiv(C, 27) * 105LL + ceilDiv(P, 30) * 120LL + G * 9LL;
}
