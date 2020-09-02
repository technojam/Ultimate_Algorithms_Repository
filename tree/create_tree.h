# pragma once
class Node{
public:
  int data;
  Node* right_child;
  Node* left_child;
};
class create_tree{

public:
  static void add_root(Node** root,int data); //Node* in place of Node**
  static void add_node(Node* root,int data);

};
