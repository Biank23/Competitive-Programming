#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e6 + 9;
const int ALPHA = 4;
 
const map<char, int> val{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
const string letter = "ACGT";
 
int nextPos[MAX_N][ALPHA];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    
    int n = ssize(s);
    for (int i = 0; i < ALPHA; i++) {
        nextPos[n][i] = n + 1;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < ALPHA; j++) {
            nextPos[i][j] = nextPos[i + 1][j];
        }
        nextPos[i][val.at(s[i])] = i + 1;
    }
    
    string subsequence = "";
    int i = 0;
    while (i <= n) {
        int k = 0;
        for (int j = 1; j < ALPHA; j++) {
            if (nextPos[i][j] > nextPos[i][k]) k = j;
        }
        i = nextPos[i][k], subsequence += letter[k];
    }
    cout << subsequence << '\n';
    
    return 0;
}