#include<iostream>
#include<math.h>
using namespace std; 
  
void fun(int n, int* square, double* sq_root)   //square and sq_root is pointing to sq and sq_root in main stack respectively (changes will reflect)
{ 
    *square = n * n; 
    *sq_root = sqrt(n); 
} 
  
int main() 
{ 
  
    int n = 100; 
    int* sq = new int; 
    double* sq_root = new double; 
    fun(n, sq, sq_root);                         //call by pointer
    cout << *sq << " " << *sq_root; 
    return 0; 
} 
