#include <bits/stdc++.h>
#include "compresion.h";
 
using namespace std;

#define sz(x) int(x.size())

using ll = long long;
 
vector<ll> comprimir(vector<ll> original) {
    map<ll, int> freq;
    for (ll &x : original) freq[x]++;
    int prev = 0;
    vector<ll> res;
    for (auto [num, cant] : freq) {
        int diff = num - prev;
        res.push_back(diff);
        res.push_back(cant);
        prev = num;
    }
    return res;
}

vector<ll> descomprimir(vector<ll> transformada) {
    vector<ll> res;
    int prev = 0;
    for (int i = 0; i < sz(transformada); i += 2) {
        int diff = transformada[i];
        int cant = transformada[i + 1];
        int num = prev + diff;
        while (cant--) res.push_back(num);
        prev = num;
    }
    return res;
}