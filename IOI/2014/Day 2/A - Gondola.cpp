#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

int findFirst(int n, int a[]) {
    int pos = n;
    for (int i = 0; i < n; i++) {
        if (a[i] <= n) pos = (1 + i - a[i] + n) % n;
    }
    return pos;
}

int valid(int n, int inputSeq[]) {
    int pos = findFirst(n, inputSeq);
    set<int> numbers(inputSeq, inputSeq + n);
    if (sz(numbers) != n) return false;
    for (int i = 0; i < n; i++) {
        int x = inputSeq[(i + pos) % n];
        if (x <= n && x != i + 1) return false;
    }
    return true;
}

int replacement(int n, int gondolaSeq[], int replacementSeq[]) {
    int pos = findFirst(n, gondolaSeq);
    int maxi = *max_element(gondolaSeq, gondolaSeq + n);
    int l = maxi - n;
    for (int i = 0; i < n; i++) {
        int x = gondolaSeq[(i + pos) % n];
        if (x != i + 1) replacementSeq[x - n - 1] = i + 1;
    }
    int last = l - 1;
    for (int i = l - 1; i >= 0; i--) {
        if (replacementSeq[i]) continue;
        replacementSeq[i] = replacementSeq[last];
        replacementSeq[last] = n + i + 1;
        last = i;
    }
    return l;
}

const int MOD = 1e9 + 9;

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

int binpow(int a, int k) {
    int r = 1;
    while (k > 0) {
        if (k & 1) r = mul(r, a);
        a = mul(a, a), k /= 2;
    }
    return r;
}

int countReplacement(int n, int inputSeq[]) {
    if (!valid(n, inputSeq)) return 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (inputSeq[i] > n) v.push_back(inputSeq[i]);
    }
    sort(all(v));
    if (v.empty()) return 1;
    int ans = findFirst(n, inputSeq) == n ? n : 1;
    int l = n + 1;
    for (int i = 0; i < sz(v); i++) {
        int r = v[i] - 1;
        ans = mul(ans, binpow(sz(v) - i, r - l + 1));
        l = v[i] + 1;
    }
    return ans;
}

