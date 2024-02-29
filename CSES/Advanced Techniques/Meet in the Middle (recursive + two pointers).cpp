#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
#define size(x) (int)x.size()
 
int target;
 
void getSums(const vector<int> &v, vector<int> &sums, int i = 0, int curSum = 0) {
    if (curSum > target) return;
    if (i == size(v)) {
        sums.push_back(curSum);
        return;
    }
    getSums(v, sums, i + 1, curSum);
    getSums(v, sums, i + 1, curSum + v[i]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n >> target;
    
    vector<int> v[2], sums[2];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i&1].push_back(x);
    }
    for (int i = 0; i < 2; i++) {
        getSums(v[i], sums[i]);
    }
    sort(all(sums[0]));
    sort(all(sums[1]), greater<int>());
    
    long long res = 0;
    int l = 0, r = 0;
    for (const int &x : sums[1]) {
        while (l < size(sums[0]) && sums[0][l] < target - x) l++;
        while (r < size(sums[0]) && sums[0][r] <= target - x) r++;
        res += r - l;
    }
    cout << res << '\n';
    
    return 0;
}