#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n1,n2,n3,i=0,j=0,t1=0;
    cin>>n1>>n2;
    n3=n1+n2;
    int a1[n1],a2[n2],a3[n3];

    for(int i1=0;i1<n1;i1++)
        cin>>a1[i1];
    for(int i1=0;i1<n2;i1++)
        cin>>a2[i1];

    // for(;i<n1 && j<n2;)			//while(i<n1 && j<n2)
    // {
    //     if(a1[i]<a2[j])
    //         {
    //             a3[t1++] = a1[i++];
    //         }
    //     else
    //         {
    //             a3[t1++] = a2[j++];
    //         }
    // }
    //
    // for(;j<n2;)
    // {
    //     a3[t1++] = a2[j++];
    // }
    // for(;i<n1;)
    // {
    //     a3[t1++] = a1[i++];
    // }

    while(i+j<n1+n2)
    {
        if(i == n1)
            a3[t1++] = a2[j++];
        else if(j == n2)
            a3[t1++] = a1[i++];
        else if(a1[i] < a2[j])
            a3[t1++] = a1[i++];
        else if(a1[i] > a2[j])
            a3[t1++] = a2[j++];
    }
    for(int i1=0;i1<n3;i1++)
        cout<<a3[i1]<<endl;

}
