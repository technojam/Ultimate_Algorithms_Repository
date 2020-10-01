
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node *right;
};

// Make a new_node
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

bool search(Node *root, int val) {
	if (root == NULL) return false;
	if (root -> data == val) return true;
	if (val <= root -> data) return search(root -> left, val);
	return search(root -> right, val);
}

int find_height(Node* root) {
	if (root == NULL) return -1;
	return max(find_height(root -> left), find_height(root -> right)) + 1;
}
int main(void) {
	Node* root = NULL;
	vector <int> keys {15, 10, 20, 25, 8, 12, 50, 1};
	for (auto i : keys) root = Insert(root, i);
		if (search(root, 20)) cout << "found!";
	else cout << "not found!";
}

