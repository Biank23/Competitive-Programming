#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    map<string, int> cant;
    string longest = "";
    string mostFrequent = "";
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        cant[name]++;
        if (sz(longest) < sz(name)) {
            longest = name;
        }
        if (cant[mostFrequent] < cant[name]) {
            mostFrequent = name;
        }
    }
    cout << longest << '\n';
    cout << mostFrequent << '\n';
    
    return 0;
}
