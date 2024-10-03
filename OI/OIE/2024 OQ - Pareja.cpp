#include <bits/stdc++.h>

using namespace std;

int n;

bool query(vector<int> v) {
    cout << "? ";
    for (int x = 0; x < n; x++) cout << v[x] << ' ';
    cout << endl;
    char res;
    cin >> res;
    return res == 'd';
}

vector<int> divideByBit(int i) {
    vector<int> v(n);
    for (int x = 0; x < n; x++) {
        v[x] = (x >> i & 1) + 1;
    }
    return v;
}

int findFirstDifference() {
    for (int i = 0; i < 14; i++) {
        if (query(divideByBit(i))) return i;
    }
    assert(false);
}

int findCommonSuffix(int i) {
    vector<int> v = divideByBit(i);
    int l = 0, r = (1 << i);
    while (l + 1 < r) {
        int m = (l + r) / 2;
        vector<int> c = v;
        for (int x = 0; x < n; x++) {
            if ((x & ((1 << i) - 1)) < m) c[x] = 2;
        }
        if (query(c)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int findPrefix(int i, int t) {
    vector<int> v = divideByBit(i);
    int l = 0, r = (1 << (13 - i));
    while (l + 1 < r) {
        int m = (l + r) / 2;
        vector<int> c = v;
        for (int x = 0; x < n; x++) {
            if ((x >> (i + 1)) < m) c[x] = t;
        }
        if (query(c)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    
    cin >> n;
    int i = findFirstDifference();
    int suff = findCommonSuffix(i);
    int A = (findPrefix(i, 2) << (i + 1)) + suff;
    int B = (findPrefix(i, 1) << (i + 1)) + (1 << i) + suff;
    if (B < A) swap(A, B);
    cout << "! " << A + 1 << ' ' << B + 1 << endl;
    
    return 0;
}