#include "dna.h"
#include <cstdlib>
 
using namespace std;
 
#define sz(x) int(x.size())
 
string analyse(int n, int t) {
    int lo = 0, hi = n + 1;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (make_test(string(mid, '0'))) lo = mid;
        else hi = mid;
    }
    int K = lo;
    string S = string(K, '0');
    while (sz(S) < n) {
        if (make_test(S + '1')) S += '1';
        else S += '0';
        if (sz(S) > K && S.substr(sz(S) - K - 1) == string(K + 1, '0')) break;
    }
    lo = K, hi = sz(S) + 1;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (make_test(S.substr(0, mid))) lo = mid;
        else hi = mid;
    }
    S = S.substr(0, lo);
    while (sz(S) < n) {
        if (make_test("1" + S)) S = "1" + S;
        else S = "0" + S;
    }
    return S;
}