#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
  
using namespace std;
using namespace __gnu_pbds; 

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //https://en.wikipedia.org/wiki/Factorial_number_system
    const int N = 10;
    const int TARGET = 1e6;

    int val = TARGET - 1;
    vector<int> rem;
    //
    for (int div = 1; div <= N; div++) {
        rem.push_back(val % div);
        val /= div;
    }
    reverse(all(rem));
    /*for (int i = 0; i < N; i++) {
        if (i > 0) cerr << "+ ";
        cerr << rem[i] << " * " << N - i - 1 << "! ";
    }*/

    ordered_set<int> base;
    for (int num = 0; num < N; num++) {
        base.insert(num);
    }

    for (int i = 0; i < N; i++) {
        int digit = *base.find_by_order(rem[i]);
        cout << digit;
        base.erase(digit);
    }

    return 0;
}