#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    const int K = 10;
    vector<int> freq(K, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        --x;
        if (x < K) freq[x]++;
    }
    for (int i = 0; i < K; i++) {
        cout << freq[i] << '\n';
    }
    
    return 0;
}
