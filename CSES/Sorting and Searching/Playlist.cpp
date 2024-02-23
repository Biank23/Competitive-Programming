#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> id(n);
    for (int i = 0; i < n; i++) {
        cin >> id[i];
    }
    set<int> songs;
    int l = 0, longest = 0;
    for (int r = 0; r < n; r++) {
        while (songs.count(id[r])) {
            songs.erase(id[l]);
            l++;
        }
        songs.insert(id[r]);
        longest = max(longest, r - l + 1);
    }
    cout << longest << '\n';
    
    return 0;
}
