#include<bits/stdc++.h>

using namespace std;

int main()
{
     string str;
     cin>>str;
     bool flag=true;
     for(int i=0;i<str.length()/2;i++)
     {
          if(str[i]!=str[str.length()-i-1])
          {
               flag=false;
               break;
          }
     }
     if(flag)
          cout<<"true";
     else
          cout<<"false";
}
