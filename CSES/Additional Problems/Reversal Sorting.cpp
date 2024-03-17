#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9;
 
struct Node;
using NodePtr = Node*;
 
struct Node {
    int val = -INF, p, mini = INF, sz = 0;
    bool r = false;
    NodePtr left, right;
 
    Node(int x) {
        p = rand(), mini = val = x, sz = 1;
        left = right = nullptr;
    }
};
 
int size(NodePtr root) {
    if (!root) return 0;
    return root->sz;
}
 
int min(NodePtr root) {
    if (!root) return INF;
    return root->mini;
}
 
void evaluate(NodePtr root) {
    if (root) {
        root->sz = size(root->left) + size(root->right) + 1;
        root->mini = min({root->val, min(root->left), min(root->right)});
    }
}
 
void propagate(NodePtr root) {
    if (root && root->r) {
        if (root->left) root->left->r ^= true;
        if (root->right) root->right->r ^= true;
        swap(root->left, root->right);
        root->r = false;
    }
}
 
pair<NodePtr, NodePtr> split(NodePtr root, int amount) {
    if (!root) return {nullptr, nullptr};
    
    propagate(root);
    int take = size(root->left) + 1;
    if (take <= amount) {
        auto [left, right] = split(root->right, amount - take);
        root->right = left;
        evaluate(root);
        return {root, right};
    } else {
        auto [left, right] = split(root->left, amount);
        root->left = right;
        evaluate(root);
        return {left, root};
    }
}
 
NodePtr merge(NodePtr left, NodePtr right) {
    if (!left) return right;
    if (!right) return left;
    
    propagate(left), propagate(right);
    if (left->p > right->p) {
        left->right = merge(left->right, right);
        evaluate(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        evaluate(right);
        return right;
    }
}
 
void heapify(NodePtr root) {
    if (!root) return;

    NodePtr maxi = root;
    if (root->left && root->left->p > maxi->p) {
        maxi = root->left;
    }
    if (root->right && root->right->p > maxi->p) {
        maxi = root->right;
    }
    if (maxi != root) {
        swap(maxi->p, root->p);
        heapify(maxi);
    }
}
 
NodePtr build(const vector<int> &v, int l, int r) {
    if (l == r) return nullptr;

    int m = (l + r) / 2;
    NodePtr root = new Node(v[m]);
    root->left = build(v, l, m);
    root->right = build(v, m + 1, r);
    heapify(root);
    evaluate(root);
    return root;
}
 
int find(NodePtr root, int val) {
    if(!root) return 0;
    
    propagate(root);
    evaluate(root);
    int sz = size(root->left) + 1;
    if (root->val == val) return sz;
    if (min(root->left) == val) return find(root->left, val);
    return sz + find(root->right, val);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    NodePtr root = build(x, 0, n);
    
    cout << n - 1 << '\n';
    for (int i = 0; i < n - 1; i++) {
        NodePtr left, middle, right;
        tie(left, right) = split(root, i);
        int j = find(right, i+1);
        tie(middle, right) = split(right, j);
        middle->r ^= true;
        root = merge(merge(left, middle), right);
        cout << i + 1 << ' ' << i + j << '\n';
    }
    
    return 0;
}