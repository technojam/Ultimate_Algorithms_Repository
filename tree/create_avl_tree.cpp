#include<iostream>
#include "create_tree.h"

int max(int a,int b){
  return a>b?a:b;
}

int height(Node* node){
  int ldepth,rdepth=0;
  if (node==nullptr)
  return 0;
  else{
    ldepth=height(node->left_child);
    rdepth=height(node->right_child);
  }
  return max(ldepth,rdepth)+1;
}

Node* left_rotate(Node* node){
  Node* x=node->right_child;
  Node* y=x->left_child;

  x->left_child=node;
  node->right_child=y;

  return x;
}
Node* right_rotate(Node* node){
  Node* x=node->left_child;
  Node* y=x->right_child;

  x->right_child=node;
  node->left_child=y;

  return x;
}

int main(){
  Node* root=new Node;
  create_tree tree;
  tree.add_root(&root,56);
  tree.add_node(root,52);
  tree.add_node(root,25);
  tree.add_node(root,19);
  tree.add_node(root,27);
  tree.add_node(root,26);
  tree.add_node(root,57);
  tree.add_node(root,59);
  root=left_rotate(root);
  std::cout << root->data << '\n';
  int h=height(root);
  std::cout << "height of root-->" <<h<< '\n';
  return 0;
}
