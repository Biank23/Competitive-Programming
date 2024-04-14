#include "coins.h"

using namespace std;

#define sz(x) int(x.size())

vector<int> coin_flips(vector<int> b, int c) {
    int x = 0;
    for (int i = 0; i < sz(b); i++) {
        if (b[i]) x ^= i;
    }
    return {x ^ c};
}

int find_coin(vector<int> b) {
    int x = 0;
    for (int i = 0; i < sz(b); i++) {
        if (b[i]) x ^= i;
    }
    return x;
}
