#include<iostream>

class StackNode {
  public:
    int val;
    StackNode *next = nullptr;

    StackNode (int v) {
      val = v;
    }
};

class Stack {
  public:
    StackNode *top = nullptr;

    void push (int value) {
      if (top == nullptr) {
        top = new StackNode(value);
      }
      else {
        StackNode* newNode = new StackNode(value);
        newNode->next = top;
        top = newNode;
      }
    }

    int pop () {
      int returnVal = top->val;
      top = top->next;
      return returnVal;
    }

    void print () {
      StackNode* temp = top;

      while (temp) {
        std::cout<<temp->val<<std::endl;
        temp = temp->next;
      }
    }
};

void moveNodesFromTo (int num, Stack *source, Stack *target, Stack *missing) {
  if (num == 1) {
    target->push(source->pop());
  }
  else if (num == 2) {
    missing->push(source->pop());
    target->push(source->pop());
    target->push(missing->pop());
  }
  else {
    moveNodesFromTo(num - 1, source, missing, target);
    moveNodesFromTo(1, source, target, missing);
    moveNodesFromTo(num-1, missing, target, source);
  }
}

int main () {
  Stack A, B, C;

  A.push(5);
  A.push(4);
  A.push(3);
  A.push(2);
  A.push(1);

  moveNodesFromTo(5, &A, &C, &B);
  C.print();

}
