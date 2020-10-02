#include<iostream>
using namespace std;
void bubble_sort(int a[],int len)
{
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<=(len-i-1);j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    cout<<"Sorted array is:"<<endl;
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int a[1000],len;
    cout<<"Enter length of array:";
    cin>>len;
    cout<<"Enter elements of array:";
    for(int i=0;i<len;i++){
        cin>>a[i];
    }
    bubble_sort(a,len);
}
