#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  double a;
  cout<<"enter a number";
  cin>>a;
  if(pow(a,0.5)==floor(pow(a,0.5)))
    cout<<"Perfect Square";
  else
    cout<<"Not a Perfect Square";
  return 0;
}
