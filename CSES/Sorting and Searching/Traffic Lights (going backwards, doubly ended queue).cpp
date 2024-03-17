#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ii = pair<int, int>;
#define fst first
#define snd second
 
struct Node;
using NodePtr = Node*;
 
struct Node {
    int val;
    NodePtr prev, next;
    Node(int v, NodePtr p = nullptr, NodePtr n = nullptr) {
        val = v, prev = p, next = n;
    }
};
 
NodePtr erase(NodePtr u) {
    u->next->prev = u->prev;
    return u->prev->next = u->next;
}
 
NodePtr insert(NodePtr u, int val) {
    return u->next = new Node(val, u, u->next);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int x, n;
    cin >> x >> n;
 
    vector<ii> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].fst;
        p[i].snd = i;
    }
    sort(all(p));
    
    vector<NodePtr> light(n);
    NodePtr it = new Node(0, nullptr, new Node(x));
    int maxDist = 0;
    for (int i = 0; i < n; i++) {
        it = insert(it, p[i].fst);
        light[p[i].snd] = it;
        maxDist = max(maxDist, it->val - it->prev->val);
    }
    maxDist = max(maxDist, x-it->val);
    
    vector<int> res(n);
    res[n - 1] = maxDist;
    for (int i = n - 1; i >= 1; i--) {
        it = erase(light[i]);
        res[i - 1] = max(res[i], it->val - it->prev->val);
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}