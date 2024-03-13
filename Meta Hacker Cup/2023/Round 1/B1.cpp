#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;
using ll = long long;

vi getFactors(int x) {
    vi f;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            f.push_back(i);
            x /= i;
        }
    }
    if (x != 1) f.push_back(x);
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 1 ; tt <= TT; tt++) {
        cout << "Case #" << tt << ": ";
        int P;
        cin >> P;
        
        vi f = getFactors(P);
        
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        auto top = [&]() {
            int v = pq.top();
            pq.pop();
            return v;
        };
        for (int i : f) {
            sum += i;
            pq.push(i);
        }
        
        while (sz(pq) >= 2) {
            int a = top(), b = top();
            int c = a * b;
            int newSum = sum - a - b + c;
            if (newSum <= 41) {
                sum = newSum;
                pq.push(c); 
            } else {
                pq.push(a), pq.push(b);
                break;
            }
        }
        
        while (sum < 41) {
            pq.push(1), sum++;
        }
        
        if (sum > 41 || sz(pq) > 100) {
            cout << "-1\n";
            continue;
        }
        
        cout << sz(pq) << ' ';
        while (!pq.empty()) {
            cout << top() << ' ';
        }
        cout << '\n';
    }
}