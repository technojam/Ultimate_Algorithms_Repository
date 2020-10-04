#include<bits/stdc++.h>
int getNthFromLast(Node *head, int n)
{
    vector<int> s;
    Node* ptr = head;
    while(ptr!=NULL)
    {
        s.push_back(ptr->data);
        ptr=ptr->next;
    }
    
    reverse(s.begin(), s.end());
     int a;
     
     if(n>s.size())
     {
         a=-1;
     }
     else {
         a=s[n-1];
     }
    return a;
}