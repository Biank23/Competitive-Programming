#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

ll inversions(vector<int> &a, int j = -1) {
    if (j != -1) a[j] ^= 1;
    ll count = 0;
    int ones = 0;
    for (int i = 0; i < sz(a); i++) {
        if (a[i] == 1) ones++;
        else count += ones;
    }
    if (j != -1) a[j] ^= 1;
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll maxi = inversions(a);
        int i = 0;
        while (i < n && a[i] == 1) i++;
        if (i < n) maxi = max(maxi, inversions(a, i));
        i = n - 1;
        while (i >= 0 && a[i] == 0) i--;
        if (i >= 0) maxi = max(maxi, inversions(a, i));
        cout << maxi<< '\n';
    }
    
    return 0;
}
