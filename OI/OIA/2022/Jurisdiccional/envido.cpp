#include <bits/stdc++.h>

using namespace std;

int envido(int numero1, string &palo1, int numero2, string &palo2, int numero3, string &palo3) {
    const int N = 3;
    int num[N] = {numero1, numero2, numero3};
    string palo[N] = {palo1, palo2, palo3};
    for (int i = 0; i < N; i++) {
        if (num[i] >= 10) num[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        ans = max(ans, num[i] + (20 + num[j]) * (palo[i] == palo[j]));
    }
    return ans;
}
