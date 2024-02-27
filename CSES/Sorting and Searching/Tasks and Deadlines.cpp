#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> task(n);
    for (auto &[duration, deadline] : task) {
        cin >> duration >> deadline;
    }
    sort(all(task));
    
    ll reward = 0, finishTime = 0;
    for (auto [duration, deadline] : task) {
        finishTime += duration;
        reward += deadline - finishTime;
    }
    cout << reward << '\n';
    
    return 0;
}