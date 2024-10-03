#include <bits/stdc++.h>
#include "grader.h"
 
using namespace std;
 
#define sz(x) int(x.size())
 
int query(int k, int a, int b) {
    vector<int> s(a, k);
    while (b--) s.push_back(k ^ 1);
    return k ^ 1 ^ isSubsequence(s);
}
 
vector<int> findSequence(int N) {
    vector<int> s0, s1;
    int n = 0, k = -1;
    while (true) {
        s0.push_back(0);
        if (!isSubsequence(s0)) {
            k = 0;
            break;
        }
        s1.push_back(1);
        if (!isSubsequence(s1)) {
            k = 1;
            break;
        }
        n++;
    }
    int m = N - n;
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m) {
        int x = -1;
        if (i + m - j < j + n - i) {
            x = query(k, i + 1, m - j);
        } else {
            x = query(k ^ 1, j + 1, n - i);
        }
        if (x == k) i++;
        else j++;
        ans.push_back(x);
    }
    while (i < n) ans.push_back(k), i++;
    while (j < m) ans.push_back(k ^ 1), j++;
    return ans;
}
 