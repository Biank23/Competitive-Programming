#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Node {
    ll key;
    int priority;
    ll diff;
    int sz;
    Node *left, *right;
    Node(ll v) {
        key = v;
        priority = rand();
        diff = v;
        sz = 1;
        left = nullptr;
        right = nullptr;
    }
};

int getSize(Node* u) {
    if (!u) return 0;
    return u->sz;
}

ll getDiff(Node *u) {
    if (!u) return 0;
    return u->diff;
}

void evaluate(Node* u) {
    if (!u) return;
    u->sz = getSize(u->left) + getSize(u->right) + 1;
    u->diff = getDiff(u->right);
    if (getSize(u->right) % 2 == 0) {
        u->diff += u->key;
        u->diff -= getDiff(u->left);
    } else {
        u->diff -= u->key;
        u->diff += getDiff(u->left);
    }
    
}

pair<Node*, Node*> splitByKey(Node* root, ll k) {
    if (!root) return {nullptr, nullptr};
    if (root->key <= k) {
        auto [left, right] = splitByKey(root->right, k);
        root->right = left;
        evaluate(root);
        return {root, right};
    } else {
        auto [left, right] = splitByKey(root->left, k);
        root->left = right;
        evaluate(root);
        return {left, root};
    }
}

pair<Node*, Node*> splitByAmount(Node* root, int amount) {
    if (!root) return {nullptr, nullptr};
    int take = getSize(root->left) + 1;
    if (take <= amount) {
        auto [left, right] = splitByAmount(root->right, amount - take);
        root->right = left;
        evaluate(root);
        return {root, right};
    } else {
        auto [left, right] = splitByAmount(root->left, amount);
        root->left = right;
        evaluate(root);
        return {left, root};
    }
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        evaluate(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        evaluate(right);
        return right;
    }
}

Node* root = nullptr;
ll sum = 0;

ll agregar(ll x) {
    sum += x;
    auto [left, right] = splitByKey(root, x);
    root = merge(merge(left, new Node(x)), right);
    return (sum + getDiff(root)) / 2;
}

ll sacar(ll x) {
    sum -= x;
    Node *left, *middle, *right;
    tie(left, right) = splitByKey(root, x - 1);
    tie(middle, right) = splitByAmount(right, 1);
    assert(middle->key == x);
    root = merge(left, right);
    return (sum + getDiff(root)) / 2;
}
