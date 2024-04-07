#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

int main() {
    freopen("polimorfo.in", "r", stdin);
	freopen("polimorfo.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    vector<int> freq(k, 0);
    int zeros = k;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0 && a[i] < k) {
            freq[a[i]]++;
            if (freq[a[i]] == 1) zeros--;
        }
        if (i >= k && a[i - k] >= 0 && a[i - k] < k) {
            freq[a[i - k]]--;
            if (freq[a[i - k]] == 0) zeros++;
        }
        if (zeros == 0) {
            ans.push_back(i - k + 2);
        }
    }
    int cant = sz(ans);
    cout << cant << '\n';
    if (cant <= 10) {
        for (int p : ans) cout << p << ' ';
    } else {
        for (int i = 0; i < 5; i++) cout << ans[i] << ' ';
        for (int i = cant - 5; i < cant; i++) cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
