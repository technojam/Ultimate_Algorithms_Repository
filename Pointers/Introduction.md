# Pointers

Pointers are symbolic representation of addresses. They enable programs to simulate call-by-reference as well as to create and manipulate dynamic data structures.
The pointer in C++ language is a variable, it is a locator or indicator that points to an address of a value.


## Syntax:

datatype *var_name; 

int *ptr;   //ptr can point to an address which holds int data

char *c;    //c can point to an address which holds char data


## Assigning the address of a variable to pointer
int num=10;

method 1: 

int* ptr;     
ptr= & num;

method 2:
int* ptr= & num;


## Printing Values
cout<<num<<endl;      // print 10

cout<<ptr<<endl;      // print address i.e. 0x8fcbb....

cout<<*ptr<<endl;     // print 10 
