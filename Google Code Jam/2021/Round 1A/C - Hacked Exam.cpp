#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using tint = __int128;

tint gcd(tint a, tint b){
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ostream &operator<<(ostream &os, tint &n) {
    string num = "";
    do num += char('0' + n % 10);
    while (n /= 10);
    reverse(all(num));
    return os << num;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    const int MAX_Q = 150;
    tint bin[MAX_Q][MAX_Q];
    for (int n = 0; n < MAX_Q; n++) {
        bin[n][0] = bin[n][n] = 1;
        for (int k = 1; k < n; k++) {
            bin[n][k] = bin[n - 1][k] + bin[n - 1][k - 1];
        }
    }
    
    int TT;
    cin >> TT;
    for (int tt = 1; tt <= TT; tt++) {
        int n, q;
        cin >> n >> q;
        vector<string> s(n);
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i] >> v[i];
        }
        while (n < 3) {
            s.push_back(s.back());
            v.push_back(v.back());
            n++;
        }
        const int TYPES = 4;
        auto getType = [&](int i) {
            return 2 * (s[0][i] != s[1][i]) + (s[1][i] != s[2][i]);
        };
        vector<int> cant(TYPES, 0);
        for (int i = 0; i < q; i++) {
            cant[getType(i)]++;
        }
        tint sum = 0;
        vector<tint> count(TYPES, 0);
        vector<int> state(TYPES);
        const vector<vector<bool>> flag = {{1, 1, 1, 1},
                                           {1, 1, 0, 0},
                                           {1, 0, 0, 1}};
        for (state[0] = 0; state[0] <= cant[0]; state[0]++) {
            for (state[1] = 0; state[1] <= cant[1]; state[1]++) {
                for (state[2] = 0; state[2] <= cant[2]; state[2]++) {
                    state[3] = v[0];
                    for (int i = 0; i < TYPES - 1; i++) {
                        state[3] -= state[i];
                    }
                    if (state[3] < 0 || state[3] > cant[3]) {
                        continue;
                    }
                    vector<int> score(n, 0);
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < TYPES; j++) {
                            if (flag[i][j]) score[i] += state[j];
                            else score[i] += cant[j] - state[j];
                        }
                    }
                    if (score == v) {
                        tint ways = 1;
                        for (int i = 0; i < TYPES; i++) {
                            ways *= bin[cant[i]][state[i]];
                        }
                        sum += ways;
                        for (int i = 0; i < TYPES; i++) {
                            count[i] += ways * state[i];
                        }
                    }
                }
            }
        }
        tint num = 0, den = sum;
        vector<bool> option(TYPES);
        for (int i = 0; i < TYPES; i++) {
            tint tot = sum * cant[i];
            if (2 * count[i] >= tot) {
                option[i] = 1;
                num += count[i];
            } else {
                option[i] = 0;
                num += tot - count[i];
            }
        }
        string ans(q, '-');
        for (int i = 0; i < q; i++) {
            int t = getType(i);
            if (option[t]) {
                ans[i] = s[0][i];
            } else {
                ans[i] = char('T' + 'F' - s[0][i]);
            }
        }
        tint commonDivisor = gcd(num, den);
        if (commonDivisor != 0) {
            num /= commonDivisor;
            den /= commonDivisor;
        }
        cout << "Case #" << tt << ": " << ans << " " << num << '/' << den << '\n';
    }
    
    return 0;
}
