#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x),end(x)

const int MAX_N = 1e5 + 20;

string tipo;
vector<int> input[MAX_N];

using Node = set<int>*;

Node mergeOr(Node u, Node v) {
    for (int x : *u) {
        v->insert(x);
    }
    return v;
}

Node mergeAnd(Node u, Node v) {
    Node a = new set<int>();
    for (int x : *u) {
        if (v->count(x)) a->insert(x); 
    }
    return a;
}

Node mergeXor(Node u, Node v) {
    for (int x : *u) {
        if (v->count(x)) v->erase(x);
        else v->insert(x);
    }
    return v;
}

Node dfs(int i) {
    if (tipo[i] == 'E') {
        return new set<int>(all(input[i]));
    } else if (tipo[i] == 'L') {
        return dfs(input[i].front());
    } else {
        Node u = dfs(input[i].front());
        Node v = dfs(input[i].back());
        if (u->size() > v->size()) {
            swap(u, v);
        }
        if (tipo[i] == 'O') {
            return mergeOr(u, v);
        } else if (tipo[i] == 'A') {
            return mergeAnd(u, v);
        } else if (tipo[i] == 'X') {
            return mergeXor(u, v);
        } else {
            assert(false);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n >> tipo;
    
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        input[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> input[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (tipo[i] == 'L') {
            for (int x : *dfs(i)) {
                cout << x << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}
