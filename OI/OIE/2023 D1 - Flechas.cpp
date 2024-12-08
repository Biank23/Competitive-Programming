#include <bits/stdc++.h>

using namespace std;

#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)
#define dforn(i,n) dforsn(i,0,n)

using vi=vector<int>;
using ii=pair<int,int>;

int main(){
    iosbase::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    forn(,t){
        int n; cin>>n;
        vector<string> g(n);
        forn(i,n) cin>>g[i];
        vector<vi> r(n,vi(n,-1)),l(n,vi(n,n)),u(n,vi(n,n)),d(n,vi(n,-1));
        forn(i,n) forsn(j,1,n){
            if(g[i][j-1]=='R') r[i][j]=j-1;
            else r[i][j]=r[i][j-1];
        }
        forn(i,n) dforn(j,n-1){
            if(g[i][j+1]=='L') l[i][j]=j+1;
            else l[i][j]=l[i][j+1];
        }
        forsn(i,1,n) forn(j,n){
            if(g[i-1][j]=='D') d[i][j]=i-1;
            else d[i][j]=d[i-1][j];
        }
        dforn(i,n-1) forn(j,n){
            if(g[i+1][j]=='U') u[i][j]=i+1;
            else u[i][j]=u[i+1][j];
        }
        vector<vi> c(n,vi(n));
        forn(i,n) forn(j,n){
            if(r[i][j]!=-1) c[i][r[i][j]]++;
            if(l[i][j]!=n) c[i][l[i][j]]++;
            if(d[i][j]!=-1) c[d[i][j]][j]++;
            if(u[i][j]!=n) c[u[i][j]][j]++;
        }
        stack<ii> s;
        forn(i,n) forn(j,n){
            if(!c[i][j]) s.emplace(i,j);
        }
        int k=0;
        while(!s.empty()){
            auto[i,j]=s.top();
            s.pop(),k++;
            if(r[i][j]!=-1&&!--c[i][r[i][j]]) s.emplace(i,r[i][j]);
            if(l[i][j]!=n&&!--c[i][l[i][j]]) s.emplace(i,l[i][j]);
            if(d[i][j]!=-1&&!--c[d[i][j]][j]) s.emplace(d[i][j],j);
            if(u[i][j]!=n&&!--c[u[i][j]][j]) s.emplace(u[i][j],j);
        }
        if(k==n*n) cout<<"POSIBLE\n";
        else cout<<"IMPOSIBLE\n";
    }

    return 0;
}