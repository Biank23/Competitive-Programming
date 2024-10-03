#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5e5 + 9;
const int MAX_L = 19;

using ll = long long;

int jump[MAX_L][MAX_N];
int h[MAX_L][MAX_N];

const int B = 4473;
const int M = 1e9 + 9;

int mul(int a, int b) {
    return int((ll) a * b % M);
}

int st[2 * MAX_N];
int n;
string s;
 
string get(int i) {
    string ans = "";
    while (i != n) {
        ans += s[i];
        i = jump[0][i];
    }
    return ans;
}
 
int op(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    int oa = a, ob = b;
    for (int i = MAX_L -  1; i >= 0; i--) {
        if (h[i][a] == h[i][b]) {
            a = jump[i][a];
            b = jump[i][b];
        }
    }
    return s[a] < s[b] ? oa : ob;
}
 
int query(int l, int r) {
    int ansL = -1, ansR = -1;
    for (l += MAX_N, r += MAX_N; l < r; l /= 2, r /= 2) {
        if (l & 1) ansL = op(ansL, st[l++]);
        if (r & 1) ansR = op(st[--r], ansR);
    }
    return op(ansL, ansR);
}

void update(int p) {
    p += MAX_N;
    st[p] = p - MAX_N;
    while (p /= 2) {
        st[p] = op(st[2 * p], st[2 * p + 1]);
    }
}
 
const int MAX_K = 26;

bool a[MAX_K][MAX_K];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int c;
    cin >> c >> n;
    for (int i = 0; i < c; i++) {
        string t;
        cin >> t;
        for (int j = 0; j < c; j++) {
            a[i][j] = t[j] == '1';
        }
    }
    cin >> s;
    s += char('a' - 1);
    
    vector<int> r(n);
    for (int i = n - 1; i >= 0; i--) {
        r[i] = i + 1;
        while (r[i] != n && a[s[i] - 'a'][s[r[i]] - 'a']) {
            r[i] = r[r[i]];
        }
    }
    
    vector<int> powB(MAX_L);
    powB[0] = B;
    for (int i = 1; i < MAX_L; i++) {
        powB[i] = mul(powB[i - 1], powB[i - 1]);
    }
    for (int i = 0; i < MAX_L; i++) {
        jump[i][n] = n;
    }
    memset(st, -1, sizeof st);
    update(n);
    for (int i = n - 1; i >= 0; i--) {
        jump[0][i] = query(i + 1, r[i] + 1);
        h[0][i] = s[i] - 'a' + 1;
        for (int j = 1; j < MAX_L; j++) {
            int k = jump[j - 1][i];
            jump[j][i] = jump[j - 1][k];
            h[j][i] = mul(h[j - 1][i], powB[j - 1]) + h[j - 1][k];
            if (h[j][i] >= M) h[j][i] -= M;
        }
        update(i);
    }
    cout << get(0) << '\n';
    
    return 0;
}
 