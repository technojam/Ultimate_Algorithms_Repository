#include<iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node *prev;
};


void ins_bef_no(Node** head,int data, int pos_number)      // Enter the node ***before*** the position number/ given data number....
{
   Node *new_node = new Node ();
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;
    if(*head==NULL)
     { new_node->prev = NULL;
      *head = new_node;
      return;
    }

    Node *ptr = *head;
    Node *pre_ptr = *head;
    while(ptr->data!=pos_number)
    {
        pre_ptr=ptr;
        ptr=ptr->next;
    }
    ptr->prev->next = new_node;
   
    new_node->prev = ptr->prev->next;
     new_node->next=ptr;
    ptr->prev = new_node;


}
void
ins_After_no (Node ** head, int data, int pos_number)	// Doubly Linked list after the given Number....
{
  Node *new_node = new Node ();
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;

  if (*head == NULL)
    { new_node->prev = NULL;
      *head = new_node;
      return;
    }

  Node *ptr = *head;

  while (ptr->data != pos_number)
    {
      ptr = ptr->next;
    }
     ptr->next->prev = new_node;
    new_node->next = ptr->next;
        ptr->next = new_node;
        new_node->prev = ptr;

}


void
InLast (Node ** head, int x)	// Doubly linked list  Insertion at last 
{
													// Kindly Add your Driver Code...p
  Node *new_node = new Node ();
  new_node->data = x;
  new_node->next = NULL;
  new_node->prev = NULL;
  if (*head == NULL)
    {
       
      *head = new_node;
      return;
    }

  Node *ptr = *head;
  while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }

  new_node->prev = ptr;
  ptr->next = new_node;

}

void
print (Node * node)
{
  cout << "The Liked List is :: ";
  while (node != NULL)
    {                                                                           // Simple Printing Code .. 

      cout << node->data << "<-";
      node = node->next;
    }
}

int
main ()
{
  Node *head = NULL;
  int n;
  cout << "Enter the Length of the list" << endl;
  cin >> n;
  for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      InLast (&head, a);
    }
  cout << "enter the data" << " ";
  int d, e;
  cin >> d;
  cout << "Enter the data from linked list" << endl;
  cin >> e;
  ins_bef_no(&head, d, e);
  print (head);
  return 0;
}
