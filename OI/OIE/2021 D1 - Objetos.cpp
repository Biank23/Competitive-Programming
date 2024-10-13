#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> p[i];
    
    ll sum = 0LL, tot = 0LL;
    for (int i = 0; i < n; i++) {
        sum += p[i], tot += 1LL * a[i] * p[i];
    }
    
    ll prefSum = 0LL, prefTot = 0LL;
    pair<ll, int> res = {INF, -1};
    for (int i = 0; i < n; i++) {
        ll curr = a[i] * prefSum - prefTot;
        prefSum += p[i], prefTot += 1LL * a[i] * p[i];
        curr += (tot - prefTot) - a[i] * (sum - prefSum);
        res = min(res, pair<ll, int>{curr, i});
    }
    cout << res.second << '\n';
    
    return 0;
}
