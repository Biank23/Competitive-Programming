#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
void print_vector(vector<int> &a) {
    cout << ssize(a) << '\n';
    for (int &x : a) {
        cout << x << ' ';
    }
    cout << '\n'; 
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    ll sum = n * (n + 1LL) / 2;
    if (sum % 2 == 1) {
        cout << "NO\n";
        return 0;
    }
    
    vector<int> a, b;
    ll target = sum / 2;
    for (int i = n; i >= 1; i--) {
        if (i <= target) {
            target -= i;
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    
    cout << "YES\n";
    print_vector(a);
    print_vector(b);
    
    return 0;
}
