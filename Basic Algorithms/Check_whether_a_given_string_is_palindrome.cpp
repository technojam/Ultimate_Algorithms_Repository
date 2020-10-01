#include<iostream>
#include<cstdio>
using namespace std;

// isStringPalindrome() PRINTS THE STATUS OF STRING BEING PALINDROME OR NOT.
//TIME COMPLEXITYO(n/2)
//APPROACH: BY TAKING 2 FOREWARD AND BACKWARD CHARACTER POINTERS OF THE STRING AND COMPARING THE CHARACTERS SIMULTANEOUSLY.
void isStringPalindrome(char str[20])
{
    int steps = 0;
    int len = int(strlen(str));
    char *forePointer = &str[0], *backPointer = &str[len-1];
    for(int i=0; i<int(len/2)+1; i++, forePointer++, backPointer--)           //KEY PART
    {
        steps++;
        if(*forePointer != *backPointer)
        {
            cout<<str<<" is not a Palindrome.";
            return;
        }
    }
    cout<<str<<" is a Palindrome.";
}

int main()
{
    char str[20];
    gets(str);
    isStringPalindrome(str);
}
