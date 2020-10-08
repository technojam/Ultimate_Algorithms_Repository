#include <iostream>
using namespace std;

class Node                   		
{
public:
	int data;                         //data in a node of linked list
	Node *next;
	Node(int data)			// constructor to create the node
	{
		this->data = data;
		this->next = NULL;     // next pointer initially pointing to null
	}
};


Node *takeinput()					// function to take input
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;		//tail to kep track of the last node so that we don't have to traverse every time to add node
	while (data != -1)				// check if data is entered 
	{
		Node *newNode = new Node(data);
		if (head == NULL)			// if head is null, it's the first entry. 
		{
			head = newNode;			// initialise head with the newNode
			tail = newNode;			// initialise tail with the newNode
		}
		else
		{
			tail->next = newNode;		//if head!=null, add newnode to tail->next
			tail = newNode;			// move tail to newNode
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)			//function to print the linked list
{
	Node *temp = head;
	while (temp != NULL)			// print if head is not null
	{
		cout << temp->data<< " ";
		temp = temp->next;
	}
	cout << endl;
}

/*  the recursive function takes head and positon to delete the node, we call the function everytime with the next element 
until the pos =0, when pos=0, we move head to next and delete the node that holds the value of previous head.
*/
Node *deleteNodeRec(Node *head, int pos) {		// recursive function to delete a node
    if(head==NULL){					// if head is null, simply return
        return head;
    }
        
    if(pos==0){						//if pos is 0, delete the head node		
        Node *a =head;
        head=head->next;
        delete a;
        return head;
    }
    head->next = deleteNodeRec(head->next, pos-1);   //call the function with next of head and pos-1
    return head;
	
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNodeRec(head, pos);
		print(head);
	}

	return 0;
}
