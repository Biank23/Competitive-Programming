#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using vii = vector<ii>;
#define fst first
#define snd second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    map<string, pair<int, vii>> m;
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;
        m[name].fst += score;
        m[name].snd.emplace_back(i, m[name].fst);
    }
    pair<ii, string> ans = {{0, 0}, ""};
    for (auto [name, data] : m) {
        auto [finalScore, changes] = data;
        int time = 0;
        for (auto [i, score] : changes) {
            if (score >= finalScore) {
                time = i;
                break;
            }
        }
        ans = max(ans, {{finalScore, -time}, name});
    }
    cout << ans.snd << '\n';
    
    return 0;
}
