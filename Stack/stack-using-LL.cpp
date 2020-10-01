
#include<iostream>
using namespace std;

class stack{
private:
  struct node{
    node *link;
    int data;
  };
  struct node* top;
public:
  int k;
  stack(){
    top = NULL;
  }
  void Add(int);
  int pop();
  void display();
  bool isEmpty();
  int peek();
};

void stack :: Add(int ele){
  struct node *newnode = new node;
  if(!newnode){
    cout<<"Heap full";
  }
  else{
    newnode->data = ele;
    newnode->link = top;
    top = newnode;
  }
}

bool stack :: isEmpty(){
  return top == NULL;
}

int stack :: peek(){
  if(!isEmpty())
    return top->data;
  else
    cout<<"Oops underflow?\n";
}

int stack :: pop(){
  struct node *temp;
  temp =new node;
  if(top == NULL){
    cout<<"--------Stack underflow------\n";
    exit(1);
  }
  else{
    temp  = top;
    k = temp->data;
    top = top->link;
    temp->link = NULL;
    free(temp);
    return k;
  }
}

void stack :: display(){
  struct node *temp;
  if(top == NULL){
    cout<<"----------Stack underflow--------\n";
    exit(1);
  }
  else{
    temp = top;
    while(temp!=NULL){
      cout<<temp->data;
      temp = temp->link;
      if(temp!=NULL)
        cout<<"->";
    }
    cout<<"\n";
  }
}

int main(){
  int ch,ele;
  stack s;
  cout<<"\n*******STACK USING LINKED-LIST\n";
  do{
    cout<<"1.PUSH\n2.POP\n3.DISPLAY\n4.Exit\nENTER CHOICE :- ";
    cin>>ch;
    switch(ch){
      case 1:
        cout<<"Enter element to push: ";
        cin>>ele;
        s.Add(ele);
        break;
      case 2:
        cout<<"Element popped: "<<s.pop()<<endl;
        break;
      case 3:
        s.display();
        cout<<"With "<<s.peek()<<" on top ;)\n";
        break;
      default:
        cout<<"Looks like you don't wanna continue\n";
        return 0;
    }
  }while(ch!=4);
  return 0;
}
