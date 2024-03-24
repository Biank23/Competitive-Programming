#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)

#define fst first
#define snd second
 
const int MAX_N = 2000;
 
int memo[MAX_N][MAX_N];
 
int query(int i, int j){
    if (j > i) swap(i, j);
    assert(i != j);
    if (memo[i][j] == -1) {
        cout << "? " << i + 1 << ' ' << j + 1 << endl;
        cin >> memo[i][j];
    }
    return memo[i][j];
}
 
int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    srand(0);
    random_shuffle(all(p));
    
    pair<int, int> maxi = {p[0], p[1]};
    memset(memo, -1, sizeof memo);
    vector<int> ans(n);
    for (int i = 2; i < n; i++) {
        int sndMaxi = query(maxi.fst, maxi.snd);
        int curr = query(maxi.fst, p[i]);
        if (curr < sndMaxi) {
            ans[p[i]] = curr;
        } else if (curr == sndMaxi) {
            ans[maxi.fst] = sndMaxi;
            maxi.fst = p[i];
        } else {
            ans[maxi.snd] = sndMaxi;
            maxi.snd = p[i];
        }
    }
    ans[maxi.fst] = ans[maxi.snd] = query(maxi.fst, maxi.snd);
    
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    
    return 0;
}
