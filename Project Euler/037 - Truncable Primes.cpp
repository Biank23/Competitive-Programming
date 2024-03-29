#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

const int MAX_N = 1e7;

bool p[MAX_N];

void sieve() {
    for (int i = 2; i < MAX_N; i++) {
        p[i] = true;
    }
    for (int i = 2; i * i < MAX_N; i++) {
        if (!p[i]) continue;
        for (int j = i * i; j < MAX_N; j += i) {
            p[j] = false;
        }
    }
}

bool isPrime(string num) {
    return p[stoi(num)];
}

bool isLeftTruncablePrime(string num) {
    int digits = sz(num);
    if (digits < 2) return false;
    for (int i = 0; i < digits; i++) {
        if (!isPrime(num.substr(i))) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1e6;

    sieve();
    
    ll res = 0;
    int cant = 0;

    //generate right truncable primes
    queue<string> q;
    for (char digit : "2357"s) {
        q.push(""s+digit);
    }

    while (!q.empty() && cant < 11) {
        string num = q.front();
        q.pop();
        if (!isPrime(num)) continue;
        if (isLeftTruncablePrime(num)) {
            res += stoi(num);
            cant++;
        }
        for (char digit : "1379"s) {
             q.push(num + digit);
        }
    }

    cout << res << '\n';

    return 0;
}