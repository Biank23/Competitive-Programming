#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9+7;
 
using ll = long long;
 
void add(int &x, int v){
    x += v;
    if (x >= MOD) x -= MOD;
}
 
int mul(int a, int b){
    return int(1LL * a * b % MOD);
}
 
int binpow(int a, ll k) {
    int res = 1;
    while (k > 0) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a), k /= 2;
    }
    return res;
}
 
inline ll ceil(ll x, int y) {
    return (x + y - 1) / y;
}
 
int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
	ll n;
    cin >> n;
	ll s = (ll) n * n;
	int res = binpow(2, s); //0°
    add(res, binpow(2, ceil(s, 4))); //90°
	add(res, binpow(2, ceil(s, 2))); //180°
    add(res, binpow(2, ceil(s, 4))); //270°
	cout<< mul(res, binpow(4, MOD - 2)) <<'\n';
    
    return 0;
}