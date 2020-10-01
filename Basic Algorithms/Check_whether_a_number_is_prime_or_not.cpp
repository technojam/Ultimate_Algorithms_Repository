#include<iostream>
using namespace std;


// isPrime() TAKES AN INTEGER INPUT AND PRINTS THE STATUS OF THE NUMBER BEING PRIME OR NOT.
// TIME COMPLEXITY = O(√n).
void isPrime(int number)
{
    cout<<"\n";
    if(number<=1)
    {
        cout<<number<<" is not prime.";
    }
    else if(number == 2)
    {
        cout<<number<<" is prime.";
    }
    else
    {
        for(int i = 2; i*i <= number; i++)                  //KEY PART WHICH MAKES THIS ALGORITHM O(√n)
        {
            if(number%i==0)
            {
                cout<<number<<" is not prime.";
                return;
            }
        }
        cout<<number<<" is prime.";
    }
}


int main()
{
    int number;
    cout<<"Enter the number : ";
    cin>>number;
    isPrime(number);
}
