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

bool isCircularPrime(string num) {
    int digits = sz(num);
    if (digits == 0) return false;
    num += num;
    for (int j = 0; j < digits; j++) {
        if (!isPrime(num.substr(j, digits))) return false;
    }
    return true;
}

const int DIGITS = 6;
int res = 0;

void generate(string &curr) { //use only {1, 3, 7, 9}
    if (isCircularPrime(curr)) {
        res++;
    }
    if (sz(curr) < DIGITS) {
        for (char digit : "1379"s) {
            curr += digit;
            generate(curr);
            curr.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    sieve();

    res += 2; //2 and 5
    string curr="";
    generate(curr);
    cout << res << '\n';

    return 0;
}