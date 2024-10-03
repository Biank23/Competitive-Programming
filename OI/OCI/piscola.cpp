#include <bits/stdc++.h>
 
using namespace std;

int preparar_piscola(int x, int y);

using ll = long long;

const int N = 1000000000;

pair<int, int> find_next(pair<int, int> A, pair<int, int> B, bool dir) {
    ll lo = 0, hi = 1;
    auto F = [&](ll x) {
        ll p = A.first + B.first * x, q = A.second + B.second * x;
        if (p > N || q > N) return false;
        if (dir) return preparar_piscola(p, q) != 2;
        else return preparar_piscola(p, q) == 2;
    };
    while (F(hi)) {
        lo = hi;
        hi *= 2;
    }
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (F(mid)) lo = mid;
        else hi = mid;
    }
    return {A.first + B.first * lo, A.second + B.second * lo};
}

pair<int, int> piscola_perfecta() {
    pair<int, int> lo{0, 1}, hi{1, 0}, mid;
    bool flag = true;
    while (flag) {
        flag = false;
        mid = find_next(lo, hi, 0);
        flag |= lo != mid;
        lo = mid;
        mid = find_next(hi, lo, 1);
        flag |= hi != mid;
        hi = mid;
    }
    return hi;
}