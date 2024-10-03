#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x),end(x)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define forn(i,n) for(int i=0;i<int(n);i++)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
 
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
 
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;

vi reconstruct(string s, int start) {
    vector<pair<char,int>> path;
    for (char move : s) {
        if (path.empty() || path.back().fst != move) {
            path.eb(move,1);
        } else {
            path.back().snd++;
        }
    }
    int n = sz(s);
    vi p(n);
    p[0] = start == 0 ? 1 : 0;
    forsn (i, 1, n) {
        p[i] = p[i - 1] + 1;
        if (p[i] == start) p[i]++;
    }
    vi res{start};
    int i = 0, j = n - 1;
    for (auto [move, cant] : path) {
        if (move == 'L') {
            dforsn (pos, i, i + cant) {
                res.pb(p[pos]);
            }
            i += cant;
        } else {
            forsn (pos, j - cant + 1, j + 1) {
                res.pb(p[pos]);
            }
            j -= cant;
        }
    }
    return res;
}

void check(string &optimal, int c, char ch){
    bool flag=true;
    forn(i,c) if(i==sz(optimal)||optimal[i]==s) flag=false;
    if(!flag) return;
    ll mini=INF;
    forn(i,c) mini=min(mini,abs(l[i]-r[i]));
    forn(i,c){
        if(abs(l[i]-r[i])==mini){
            optimal[i]=ch;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, s;
    cin >> n >> s;
    --s;
    vll l(n, 0), r(n, 0);
    forn (i, n - 1) {
        cin >> l[i] >> r[i];
    }
    string optimal = "";
    forn (i, n - 1) {
        if (l[i] < r[i]) optimal += 'L';
        else optimal += 'R';
    }
    check(optimal, s + 1, 'R');
    check(optimal, n - s, 'L');
    ll ans = 0;
    forn (i, n) {
        if (optimal[i] == 'L') ans += l[i];
        if (optimal[i] == 'R') ans += r[i];
    }
    vi res = reconstruct(optimal, s);
    cout << ans << '\n'; 
    forn (i, n) cout << res[i] + 1 << ' ';
    cout << '\n';
    
    return 0;
}