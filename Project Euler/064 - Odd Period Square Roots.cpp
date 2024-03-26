#include <bits/stdc++.h>

using namespace std;

//https://en.wikipedia.org/wiki/Periodic_continued_fraction#Length_of_the_repeating_block
int period(int n) {
    int s = (int) sqrt(n);
    int m = 0, d = 1, a = s;
    int ans = 0;
    while (a != 2 * s) {
        m = d * a - m;
        d = (n - m * m) / d;
        a = (s + m) / d;
        ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    const int N = 1e4;
    
    int ans = 0;
    int j = 1;
    for (int i = 1; i <= N; i++) {
        if (j * j == i) {
            j++;
            continue;
        }
        if (period(i) % 2 == 1) ans++;
    }
    cout << ans << '\n';
    
    return 0;
}
