#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c,d,M=1000000007;
void fibo(int n,ll ans[])
{
    if(n==0)
    {
        ans[0]=0;
        ans[1]=1;
        return;
    }
    fibo((n/2),ans);
    a=ans[0];             // F(n)
    b=ans[1];             // F(n+1)
    c=(b*2-a+M)%M;
    c=(a*c)%M;              // F(2n)
    d=((a*a)%M+(b*b)%M)%M;  // F(2n+1)
    if(n%2==0)
    {
        ans[0]=c;
        ans[1]=d;
    }
    else
    {
        ans[0]=d;
        ans[1]=(c+d)%M;
    }
}

int main()
{
    ll n,a[2];
    cin>>n;
    fibo(n,a);
    cout<<a[0];
}
