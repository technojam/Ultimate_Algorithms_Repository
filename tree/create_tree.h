# pragma once
class Node{
public:
  int data;
  Node* right_child;
  Node* left_child;
};
class create_tree{

public:
  static void add_root(Node** root,int data);
  static void add_node(Node* root,int data);

};
