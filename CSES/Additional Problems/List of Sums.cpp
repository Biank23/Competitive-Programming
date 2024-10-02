#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    const int K = 1e9;
    const int S = n * (n - 1) / 2;
    vector<ll> B(S);
    for (int i = 0; i < S; i++) {
        cin >> B[i];
    }
    sort(all(B));
    //B[S - 1] = A[n - 1] + A[n - 2]
    //B[S - 2] = A[n - 1] + A[n - 3]
    //B[p] = A[n - 2] + A[n - 3]
    bool flag = false;
    for (int p = S - 3; p >= 0 && !flag; p--) {
        vector<ll> A(n);
        A[n - 1] = (B[S - 1] + B[S - 2] - B[p]) / 2;
        multiset<ll> s(all(B));
        flag = true;
        for (int i = n - 2; i >= 0 && flag; i--) {
            A[i] = *s.rbegin() - A[n - 1];
            for (int j = n - 1; j > i && flag; j--) {
                auto it = s.find(A[i] + A[j]);
                if (it == s.end()) flag = false;
                else s.erase(it);
            }
        }
        for (int i = 0; i < n; i++) {
            flag &= 1 <= A[i] && A[i] <= K;
        }
        if (flag) {
            for (int i = 0; i < n; i++) {
                cout << A[i] << ' ';
            }
            cout << '\n';
        }
    }
    
    
    return 0;
}