#include <iostream> 
using namespace std; 
  
void swap(int* x, int* y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
int main() 
{ 
    int x = 24, y = 20; 
    swap(&x, &y); 
    cout << x << " " << y << endl; 
    return 0; 
} 
