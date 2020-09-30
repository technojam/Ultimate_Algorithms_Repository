
#include <iostream>
using namespace std;

int main()
{
    int arr[] = { 10, 20, 30, 40 };
    
    // Compiler converts below to *(arr + 2). 
    cout << arr[2] <<endl;
    
    // So below also works.
    cout << *(arr + 2) << " ";

    return 0;
}
