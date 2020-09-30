//pointers to Dynamically allocate memory

#include <iostream> 
using namespace std; 
  
int* ptr(int n) 
{ 
    return new int[n]; 
} 
  
int main() 
{ 
    int* pt = ptr(10); 
    return 0; 
} 
