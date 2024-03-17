#include <bits/stdc++.h>

using namespace std;

const int ALPHA = 52;

int val(char c) {
    if (c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int k, n;
    cin >> k >> n;
    
    string w, s;
    cin >> w >> s;
    
    int freq[ALPHA];
    for (int i = 0; i < ALPHA; i++) {
        freq[i] = 0;
    }
    int count = 0;
    auto add = [&](int x) {
        freq[x]++;
        if (freq[x] == 1) count++;
    };
    auto erase = [&](int x) {
        freq[x]--;
        if (freq[x] == 0) count--;
    };
    
    for (int i = 0; i < k; i++) {
        add(val(w[i]));
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        erase(val(s[i]));
        if (i >= k) add(val(s[i - k]));
        if (i + 1 >= k && count == 0) ans++;
    }
    
    cout << ans << '\n';
    
    return 0;
}
