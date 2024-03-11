#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

const int N = 1000000;
bool p[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 2; i < N; i++) {
        p[i] = true;
    }
    for (int i = 2; i * i < N; i++) {
        if (!p[i]) continue;
        for (int j = i * i; j < N; j += i) {
            p[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 0; i < N; i++) {
        if (p[i]) primes.push_back(i);
    }

    int M = sz(primes);
    vector<ll> pref(M + 1);
    pref[0] = 0;
    for (int i = 0; i < M; i++) {
        pref[i + 1] = pref[i] + primes[i];
    }

    pair<int, int> ans = {0, -1};
    for (int l = 0; l < M; l++) {
        for (int r = l + ans.first; r < M; r++) {
            ll sum = pref[r + 1] - pref[l];
            if (sum >= N) break;
            if (p[sum]) ans = max(ans, {r - l + 1, sum});
        }
    }
    cout << ans.second << '\n';


    return 0;
}