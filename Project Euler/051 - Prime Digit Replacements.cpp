#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

const int MAX_N = 1e7;
bool p[MAX_N];
vector<ll> primes;

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
    for (int i = 0; i < MAX_N; i++) {
        if (p[i]) primes.push_back(i);
    }
}

bool isPrime(ll x) {
    if (x < MAX_N) return p[x];
    for (ll i : primes) { //x < 1e14
        if (i * i > x) break;
        if (x % i == 0) return false;
    }
    return true;
}

const char REPLACING = '0' + 10;

string replace(string num, char digit) {
    for (char &c : num) {
        if (c == REPLACING) c = digit;
    }
    return num;
}

pair<bool, string> check(string num) {
    if (num.find(REPLACING) == string::npos) return {false, ""};
    int count = 0;
    string first = "";
    for (int i = 0; i < 10; i++) {
        if (i == 0 && num[0] == REPLACING) continue;
        string newNum = replace(num, char('0' + i));
        if (isPrime(stoll(newNum))) {
            if (first == "") {
                first = newNum;
            }
            count++;
        }
    }
    return {count >= 8, first};
}

string generate(ll x) {
    char lastDigit = "1379"[x % 4];
    x /= 4;
    string num = ""s + lastDigit;
    do num += '0' + x % 11;
    while (x /= 11);
    reverse(all(num));
    return num;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    sieve();
    int x = 0;
    while (!check(generate(x)).first) {
        x++;
    }
    cout << check(generate(x)).second << '\n';

    return 0;
}