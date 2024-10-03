#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
 
const int MAX_N = 1e7;
 
string s;
int l[MAX_N], r[MAX_N];
 
struct Val {
    int l, r, sz;
};
 
Val solve(int u) {
    if (s[u] == '?') return {1, 1, 1};
    Val left = solve(l[u]), right = solve(r[u]), curr;
    curr.sz = left.sz + right.sz;
    if (s[u] == 'n') {
        curr.l = min(left.l, right.l);
        curr.r = left.r + right.r - 1;
    } else if (s[u] == 'x') {
        curr.l = left.l + right.l;
        curr.r = max(right.sz + left.r, left.sz + right.r);
    } else assert(false);
    return curr;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> s;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    stack<int> st;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '?' || s[i] == 'n' || s[i] == 'x') {
            st.push(i);
        } else if (s[i] == ',' || s[i] == ')') {
            int j = st.top();
            st.pop();
            if (l[st.top()] == -1) l[st.top()] = j;
            else r[st.top()] = j;
        }
    }
    Val ans = solve(st.top());
    cout << ans.r - ans.l + 1 << '\n';
    
    return 0;
}