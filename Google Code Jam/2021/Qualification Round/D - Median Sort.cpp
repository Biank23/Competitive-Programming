#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

int query(int i, int j, int k) {
    cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    int L;
    cin >> L;
    assert(L != -1);
    return L - 1;
}

void medianSort(vector<int> &v) {
    int n = sz(v);
    if (n < 3) return;
    int pivot[2] = {v[0], v[1]};
    vector<int> a[3];
    for (int i = 2; i < n; i++) {
        int q = query(pivot[0], pivot[1], v[i]);
        int part = q == pivot[0] ? 0 :
                   q == pivot[1] ? 2 :
                                   1; // q == v[i]
        a[part].push_back(v[i]);
    }
    v.clear();
    for (int i = 0; i < 3; i++) {
        medianSort(a[i]);
        int j = i < 2 ? 0 : 1;
        // 0 : pivot[1] is greater than all elements in a[i]
        // 1 : pivot[1] is less than all elements in a[i]
        if (sz(a[i]) > 1 && query(a[i][0], a[i][1], pivot[1]) == a[i][j]) {
            reverse(all(a[i]));
        }
        for (int &x : a[i]) v.push_back(x);
        if (i < 2) v.push_back(pivot[i]);
    }
}

int main() {
    int t, n, q;
    cin >> t >> n >> q;
    while (t--) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = i;
        }
        medianSort(v);
        for (int i = 0; i < n; i++) {
            cout << v[i] + 1 << ' ';
        }
        cout << endl;
        int isCorrect;
        cin >> isCorrect;
        assert(isCorrect == 1);
        cout.flush();
    }
    
    return 0;
}
