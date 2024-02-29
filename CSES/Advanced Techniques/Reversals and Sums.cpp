#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
struct Node;
using NodePtr = Node*;
 
struct Node {
	int val, p, sz;
	ll sum;
	bool r = false;
	NodePtr left, right;
 
	Node(int x) {
		p = rand(), sz = 1, sum = val = x;
		left = right = nullptr;
	}
};
 
int size(NodePtr root) {
	if (!root) return 0;
	return root->sz;
}
 
ll sum(NodePtr root) {
	if (!root) return 0;
	return root->sum;
}
 
void evaluate(NodePtr root) {
	if (root) {
		root->sz = size(root->left) + size(root->right) + 1;
		root->sum = sum(root->left) + sum(root->right) + root->val;
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
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q;
	
	cin >> n >> q;
	
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
	
	NodePtr root = build(x, 0, n);
	
	for (int i = 0; i < q; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		
		NodePtr left, middle, right;
		tie(left, right) = split(root, r);
		tie(left, middle) = split(left, l - 1);
		
		if (t == 2) cout << sum(middle) << '\n';
		else if (middle) middle->r ^= true;
		
		root = merge(merge(left, middle), right);
		
	}
}