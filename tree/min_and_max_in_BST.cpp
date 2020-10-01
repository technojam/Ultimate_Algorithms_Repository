#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node *right;
};

// create a new node
Node* get_new_node(int data) {
	Node* new_node = new Node();
	new_node -> data = data;
	return new_node;
}
// Insert a node in BST
Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = get_new_node(data);
	} else if (data <= root -> data) {
		root -> left = Insert(root -> left, data);
	} else {
		root -> right = Insert(root -> right, data);
	}
	return root;
}

int find_max(Node* root) {
	if (root == NULL) {
		cout << "tree is empty";
		return -1;
	}
	if (root -> right == NULL) return root -> data;
	return find_max(root -> right);
}

int find_min(Node* root) {
	if (root == NULL) {
		cout << "Tree is empty";
		return -1;
	} if (root -> left == NULL) return root -> data;
	return find_min(root -> left);
}

int main(void) {
	Node* root = NULL;
	vector <int> keys {15, 10, 20, 25, 8, 12, 50, 1};
	for (auto i : keys) root = Insert(root, i);
		cout << find_min(root) << endl;
	cout << find_max(root) << endl;
}

