#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
using ll = long long;
 
const int BLOCK_SIZE = 450;
const int MAX_N = 2e5 + 9;
const int CANT_BLOCKS = 1000;
 
struct Block {
    int sig;
    vector<ll> vals;
    ll diff;
    Block() {
        sig = -1;
        vals = {};
        diff = 0;
    }
    void calcDiff() {
        diff = 0;
        for (int i = 0; i < sz(vals); i += 2) diff += vals[i];
        for (int i = 1; i < sz(vals); i += 2) diff -= vals[i];
    }
    void update(ll x) {
        auto it = lower_bound(all(vals), x, greater<ll>());
        if (it == end(vals) || *it != x) {
            vals.insert(it, x);
        } else {
            vals.erase(it);
        }
        //assert(is_sorted(all(vals), greater<ll>()));
    }
};
 
Block b[CANT_BLOCKS];
int cant = 1;
 
void split(int i) {
    b[cant].vals = vector<ll>(begin(b[i].vals) + BLOCK_SIZE / 2, end(b[i].vals));
    b[cant].calcDiff();
    b[cant].sig = b[i].sig;
    b[i].vals.resize(BLOCK_SIZE / 2);
    b[i].calcDiff();
    b[i].sig = cant;
    cant++;
}
 
ll sum = 0;
 
ll query() {
    int idx = 0;
    bool parity = 0;
    ll diff = 0;
    while (idx != -1) {
        if (parity == 0) diff += b[idx].diff;
        else diff -= b[idx].diff;
        if (sz(b[idx].vals) % 2 == 1) parity ^= 1;
        idx = b[idx].sig;
    }
    return (sum + diff) / 2;
}
 
void update(ll x) {
    int idx = 0;
    while (b[idx].sig != -1 && (b[b[idx].sig].vals.empty() || b[b[idx].sig].vals.front() >= x)) {
        idx = b[idx].sig;
    }
    b[idx].update(x);
    if (sz(b[idx].vals) == BLOCK_SIZE) split(idx);
    else b[idx].calcDiff();
}
 
ll agregar(ll x) {
    sum += x;
    update(x);
    return query();
}
 
ll sacar(ll x) {
    sum -= x;
    update(x);
    return query();
}
 