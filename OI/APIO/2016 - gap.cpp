#include <bits/stdc++.h>
#include "gap.h"
 
using namespace std;
 
using ll = long long;
 
#define all(x) begin(x), end(x)
 
const ll MAX_A = 1e18;
 
ll ceilDiv(ll a, ll b) {
    return (a + b - 1) / b;
}
 
ll findGap(int T, int N) {
    if (T == 1) {
        ll mini = -1LL, maxi = MAX_A + 1LL;
        vector<ll> a(N);
        int l = 0, r = N - 1;
        while (l <= r) {
            MinMax(mini + 1, maxi - 1, &mini, &maxi);
            a[l++] = mini, a[r--] = maxi;
        }
        ll maxGap = 0LL;
        for (int i = 1; i < N; i++) {
            maxGap = max(maxGap, a[i] - a[i - 1]);
        }
        return maxGap;
    } else {
        ll mini = 0LL, maxi = MAX_A;
        MinMax(mini, maxi, &mini, &maxi);
        ll minRes = ceilDiv(maxi - mini + 1LL, N - 1);
        if (N == 2) return maxi - mini;
        ll prevMax = mini, maxGap = 0LL;
        for (ll i = mini; i <= maxi; i += minRes) {
            ll minInRange, maxInRange;
            MinMax(i, i + minRes - 1LL, &minInRange, &maxInRange);
            if (minInRange != -1) {
                maxGap = max(maxGap, minInRange - prevMax);
                prevMax = maxInRange;
            }
        }
        return maxGap;
    }
}