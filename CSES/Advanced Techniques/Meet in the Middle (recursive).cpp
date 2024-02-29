#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
#define size(x) (int)x.size()
 
int target;
 
void getSums(vector<int> &v, vector<int> &sums, int i = 0, int currSum = 0) {
    if (currSum > target) return;
    if (i == size(v)) {
        sums.push_back(currSum);
        return;
    }
    getSums(v, sums, i + 1, currSum);
    getSums(v, sums, i + 1, currSum + v[i]); 
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n >> target;
    
    vector<int> v[2];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i&1].push_back(x);
    }
    
    vector<int> sums[2];
    for (int i = 0; i < 2; i++) {
        getSums(v[i], sums[i]);
    }
    sort(all(sums[0]));
    long long res = 0;
    for (const int &x : sums[1]) {
        res += upper_bound(all(sums[0]), target - x) - lower_bound(all(sums[0]), target - x);
    }
    cout << res << '\n';
    
    return 0;
}