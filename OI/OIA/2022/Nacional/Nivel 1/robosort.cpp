#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;

vi robosort(vi &muestras) {
    int n = sz(muestras);
    vi p(n);
    for (int i = 0; i < n; i++) {
        int j = int(min_element(begin(muestras) + i, end(muestras)) - begin(muestras));
        p[i] = j + 1;
        reverse(begin(muestras) + i, begin(muestras) + p[i]);
    }
    return p;
}
