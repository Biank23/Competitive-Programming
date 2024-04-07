#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x),end(x)

const int INF = 2e9;

int mad(vector<int> &x) {
    sort(all(x));
    int n = sz(x);
    int k = n/2;
    pair<int,int> ans = {INF, -1};
    for (int i = k; i < n; i++) {
        int mad = x[i] - x[i - k];
        int t = (x[i] + x[i - k]) / 2;
        ans = min(ans, {mad, t});
    }
    return ans.second;
}
