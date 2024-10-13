#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int INF = 1e9;
const int K = 5;

struct State {
    int N;
    vector<int> v;
    State() {
        N = 0, v.assign(K, -1);
    }
    void press(int x) {
        if (v[x] == -1) {
            v[x] = ++N;
            return;
        }
        for (int i = 0; i < K; i++) {
            if (v[i] > v[x]) v[i]--;
        }
        N--, v[x] = -1;
    }
    friend bool operator<(const State &a, const State &b) {
        if (a.N != b.N) return a.N < b.N;
        return a.v < b.v;
    }
};

struct Data {
    int distance = INF, move = -1;
    State previous = State();
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    map<string,int> num;
    vector<string> word(K);
    for (int i = 0; i < K; i++) {
        cin >> word[i];
        num[word[i]] = i;
    }
    
    State s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string w; cin >> w;
        s.press(num[w]);
    }
    
    map<State, Data> mp;
    mp[s].distance = 0;
    queue<State> q;
    q.push(s);
    while (!q.empty()) {
        State u = q.front();
        q.pop();
        for (int i = 0; i < K; i++) {
            State v = u; v.press(i);
            if (!mp.count(v)) {
                mp[v].distance = mp[u].distance + 1;
                mp[v].move = i;
                mp[v].previous = u;
                q.push(v);
            }
        }
    }
    State t;
    for (int i = 0; i < K; i++) {
        t.press(i);
    }
    
    cout << mp[t].distance << '\n';
    vector<string> ans;
    while (mp[t].move != -1) {
        ans.push_back(word[mp[t].move]);
        t = mp[t].previous;
    }
    reverse(all(ans));
    for (string w : ans) {
        cout << w << '\n';
    }
    
    return 0;
}