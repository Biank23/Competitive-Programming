#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x),end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    vector<string> permutations;
    sort(all(s));
    do {
        permutations.push_back(s);
    } while (next_permutation(all(s)));
    cout << ssize(permutations) << '\n';
    for (string &p : permutations) {
        cout << p << '\n';
    }
    
    return 0;
}
