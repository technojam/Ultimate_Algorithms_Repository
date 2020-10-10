//single linked list implementation
#include<iostream>
using namespace std;

template<class T>
struct node//node creation 
{
	T data;//data part
	node *link;//link part
};

template<class T>
class SingleLinkedList
{
	node<T> *start,*temp,*ptr,*prev;
	
	public:
		SingleLinkedList()//constructor
		{
			start=NULL;
		}
		
		void insbeg(T ele)//function for insertion of node at begining 
		{
			temp=new node<T>;
			temp->data=ele;
			temp->link=NULL;
			if(start==NULL)
				start=temp;
			else
			{
				temp->link=start;
				start=temp;
			}
		}
		
		void insend(T ele)//function for insertion of node at ending
		{
			temp=new node<T>;
			temp->data=ele;
			temp->link=NULL;
			if(start==NULL)
				start=temp;
			else 
			{
				ptr=start;
				while(ptr->link!=NULL)
				ptr=ptr->link;
				ptr->link=temp;
			}
		}
		
		void inspos(T ele,T pos)//function for insertion of node at position 'pos' of value 'ele'
		{
			temp=new node<T>;ptr=new node<T>;
			temp->data=ele;
			temp->link=NULL;
			if(start==NULL)
			{
				start=temp;
				cout<<"Node added to the list"<<endl;
			}
			else if(start->link==NULL)
			{
				if(pos==1)
				{
					temp->link=start;
					start=temp;
					cout<<"Node added to the list"<<endl;
				}
				else if(pos==2)
				{
					start->link=temp;
					cout<<"Node added to the list"<<endl;
				}
				else
					cout<<"Wrong choice"<<endl;
			}
			else
			{
				int i;
				ptr=start;
				if(pos==1)
				{
					temp->link=start;
					start=temp;
					cout<<"Node added to the list"<<endl;
				}
				else
				{
					for(i=1;i<pos-1 && ptr->link!=NULL;i++)
						ptr=ptr->link;
					if(i==pos-1)
					{
						temp->link=ptr->link;
						ptr->link=temp;
						cout<<"Node added to the list"<<endl;
					}
					else
						cout<<"Wrong choice"<<endl;
				}
			}
		}
				
		void delbeg()//function for deleting node at begining 
		{
			if(start==NULL)
				cout<<"List is empty"<<endl;
			else if(start->link==NULL)
			{
				start=NULL;
				cout<<"Node deleted from list"<<endl;
			}
			else
			{
				ptr=start;
				start=start->link;
				delete ptr;
				cout<<"Node deleted from list"<<endl;
			}
		}
		
		void delend()//function for deleting node at end
		{

			if (start==NULL)
				cout<<"List is empty"<<endl;
			else
			{
				ptr=start;
				if(start->link==NULL)
					start=NULL;
				else
				{
					while(ptr->link!=NULL)
					{
						prev=ptr;
						ptr=ptr->link;
					}
					prev->link=NULL;
				}
				delete ptr;
				cout<<"Node deleted from list"<<endl;
			}
		}
		
		void delpos(T pos)//function for deleting node at position 'pos'
		{
			int i;
			if (start==NULL)
				cout<<"List is empty\n";
			else
			{
				ptr=start;
				if(start->link==NULL)
				{
					if(pos==1)
						start=NULL;
					else
						cout<<"Wrong position\n";
				}
				else
				{
					if(pos==1)
						start=start->link;
					else
					{
						for(i=1;i<pos && ptr->link!=NULL;i++)
						{
							prev=ptr;
							ptr=ptr->link;
						}
						if(i<pos)
							cout<<"Wrong position\n";
						else
							prev->link=ptr->link;
					}
				}
				delete ptr;
				cout<<"Node deleted from list"<<endl;
			}
		}

		void display()//function for displaying linked list
		{
			ptr= start;
			if (ptr==NULL)
				cout<<"Linked list is empty\n";
			else{
				cout<<"Linked list is :"<<endl;
				while(ptr->link!=NULL)
				{
					cout<<ptr->data<<"->";
					ptr=ptr->link;
				}
				cout<<ptr->data<<endl;
			}
		}
		
};

int main()//driver code
{
	SingleLinkedList<int> s;//linkend list class object
	int ch, e, p, flag=0;
	cout<<"Linked List"<<endl;
	do{
		cout<<"\nSelect an option to perform that operation on linked list\n1.Insertion at beginning\n2.Insertion at ending\n3.Insertion at position\n4.Deletion at beginning\n5.Deletion at ending\n6.Deletion at position\n7.Display linked list\n8.Exit\n"<<endl;//display menu
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Enter value of node"<<endl;
				cin>>e;
				s.insbeg(e);
				cout<<"Node added to the list"<<endl;
				break;
			case 2:cout<<"Enter value of node"<<endl;
				cin>>e;
				s.insend(e);
				cout<<"Node added to the list"<<endl;
				break; 
			case 3:cout<<"Enter value of node and position"<<endl;
				cin>>e>>p;
				s.inspos(e,p);
				break;
			case 4:s.delbeg();
				break;
			case 5:s.delend();
				break;
			case 6:cout<<"Enter position"<<endl;
				cin>>p;
				s.delpos(p);
				break;
			case 7:s.display();
				break;
			case 8:flag=1;
				cout<<"End of code\n";
				break;
			default:flag=1;
				cout<<"Wrong choice.Select correct option from given menu next time."<<endl;
				break;
		}
		if (flag)
			break;
	}while(ch<9);
	return 0;
}
