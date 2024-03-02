#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    
    map<char,int> v;
    int cant = 0;
    for (char &c : s) {
        if (!v.count(c)) v[c] = cant++;
    }
    
    vector<int> freq(cant, 0);
    int zeros = cant;
    map<vector<int>, int> m;
    ll res = 0;
    for (char &c : s) {
        m[freq]++;
        freq[v[c]]++;
        if (freq[v[c]] == 1) zeros--;
        if (zeros == 0) {
            for (int i = 0; i < cant; i++) {
                freq[i]--;
                if (freq[i] == 0) zeros++;
            }
        }
        res += m[freq];
    }
    
    cout << res << '\n';
    
    return 0;
}