#include<iostream>
using namespace std;
int a[40];int t;
void pop()
{if(t==-1)
{cout<<"\nArray is Empty";}
else
{cout<<"\nRemoved element is "<<a[--t];

}
}
void push(int n)
{if(t==40)
{cout<<"\nStack overflow";}
else
{
    a[t]=n;
    cout<<"\nPushed element is "<<a[t];t++;
}
}
void print()
{int i;
for(i=0;i<t;i++)
{cout<<"\n|"<<a[i]<<"|";}}
int main()
{ int s,c=1,n;
while(c==1)
{cout<<"\n1 for pushing an element in stack ";
cout<<"\n2 for removing an element ";
cout<<"\n3 to print the stack \n";
cin>>s;
switch(s)
{case 1:
cout<<"\nEnter the no to push in stack ";
cin>>n;
push(n);break;
case 2:
pop();
break;
case 3:
print();
break;
default:
cout<<"\nInvalid input";
}
cout<<"\nWant to continue press 1";
cin>>c;}
return 0;
}