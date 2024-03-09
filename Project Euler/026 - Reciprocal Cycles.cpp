#include <bits/stdc++.h>

using namespace std;

int cycle(int d) {
    vector<int> reminders(d, -1); //-1 -> not seen
    int x = 1;
    for (int i = 0; x != 0; i++) {
        if (reminders[x] != -1) return i - reminders[x];
        reminders[x] = i;
        x = (x * 10) % d;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1000;

    pair<int,int> ans = {0, -1};
    for (int d = 1; d < N; d++) {
        ans = max(ans, {cycle(d), d});
    }
    cout << ans.second << '\n';

    return 0;
}