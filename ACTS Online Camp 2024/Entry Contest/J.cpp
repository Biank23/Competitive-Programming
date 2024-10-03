#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9;
 
struct Node;
using NodePtr = Node*;
 
struct Node {
    int p, sz, val, c, idx, maxi;
    NodePtr left, right;
 
    Node(int v, int k, int i) {
        p = rand(), sz = 1;
        val = v, c = k, idx = i;
        maxi = val;
        left = right = nullptr;
    }
};
 
int size(NodePtr root) {
    if (!root) return 0;
    return root->sz;
}

int max(NodePtr root) {
    if (!root) return -INF;
    return root->maxi;
}
 
void evaluate(NodePtr root) {
    if (root) {
        root->sz = size(root->left) + size(root->right) + 1;
        root->maxi = max({max(root->left), max(root->right), root->val});
    }
}
 
pair<NodePtr, NodePtr> split(NodePtr root, int amount) {
    if (!root) return {nullptr, nullptr};
    
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

int find(NodePtr root, int val) {
    if(!root) return 0;
    evaluate(root);
    int sz = size(root->left) + 1;
    if (max(root->right) >= val) return sz + find(root->right, val);
    if (root->val >= val) return sz;
    return find(root->left, val);
}
 
NodePtr build(const vector<int> &a, const vector<int> &c, int l, int r) {
    if (l == r) return nullptr;
    int m = (l + r) / 2;
    NodePtr root = new Node(a[m], c[m], m + 1);
    root->left = build(a, c, l, m);
    root->right = build(a, c, m+1, r);
    heapify(root);
    evaluate(root);
    return root;
}
 
void print(NodePtr root) {
    if (!root) return;
    print(root->left);
    cout << root->idx << ' ';
    print(root->right);
} 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
    }
    NodePtr root = build(a, c, 0, n);
    for (int i = 0; i < n; i++) {
        NodePtr left, middle, pos, right;
        tie(left, right) = split(root, i);
        int j = max(find(left, a[i]), i - c[i]);
        tie(left, middle) = split(left, j);
        tie(pos, right) = split(right, 1);
        root = merge(merge(left, pos), merge(middle, right));
    }
    print(root); cout << '\n';
}