#include <bits/stdc++.h>

using namespace std;

int findSample(int n, int confidence[], int host[], int protocol[]) {
    vector<int> dp1(n), dp2(n, 0);
    for (int i = 0; i < n; i++) dp1[i] = confidence[i];
    for (int i = n - 1; i >= 1; i--) {
        if (protocol[i] == 0) {
            dp2[host[i]] += max(dp1[i], dp2[i]);
            dp1[host[i]] += dp2[i];
        } else if (protocol[i] == 1) {
            dp1[host[i]] = max({dp1[host[i]] + dp1[i], dp1[host[i]] + dp2[i], dp2[host[i]] + dp1[i]});
            dp2[host[i]] += dp2[i];
        } else {
            dp1[host[i]] = max({dp1[host[i]] + dp2[i], dp2[host[i]] + dp1[i]});
            dp2[host[i]] += dp2[i];
        }
    }
    return max(dp1[0], dp2[0]);
}
