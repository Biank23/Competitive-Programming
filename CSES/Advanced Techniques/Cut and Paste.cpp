#include <bits/stdc++.h>
 
using namespace std;
 
struct Node;
using NodePtr = Node*;
 
struct Node {
	int p, sz;
	char chr;
	NodePtr left, right;
 
	Node(char c) {
		p = rand(), sz = 1, chr = c;
		left = right = nullptr;
	}
};
 
int size(NodePtr root) {
	if (!root) return 0;
	return root->sz;
}
 
void evaluate(NodePtr root) {
	if (root) root->sz = size(root->left) + size(root->right) + 1;
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
 
NodePtr build(const string &s, int l, int r) {
	if (l == r) return nullptr;
	int m = (l + r) / 2;
	NodePtr root = new Node(s[m]);
	root->left = build(s, l, m);
	root->right = build(s, m+1, r);
	heapify(root);
	evaluate(root);
	return root;
}
 
void print(NodePtr root) {
	if (!root) return;
	print(root->left);
	cout << root->chr;
	print(root->right);
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q;
	string s;
	
	cin >> n >> q >> s;
	
	NodePtr root = build(s, 0, n);
	
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		
		NodePtr left, middle, right;
		tie(left, right) = split(root, r);
		tie(left, middle) = split(left, l-1);
		root = merge(merge(left, right), middle);
	}
	
	print(root);

	return 0;
}