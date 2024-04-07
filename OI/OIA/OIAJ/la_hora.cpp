#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string t;
    cin >> t;
    int h = stoi(t.substr(0, 2));
    string type = " AM\n";
    if (h >= 12) type[1] = 'P';
    if (h == 0) h = 12;
    else if (h > 12) h -= 12;
    cout << setw(2) << setfill('0') << h << t.substr(2, 3) << type;
    
    return 0;
}
