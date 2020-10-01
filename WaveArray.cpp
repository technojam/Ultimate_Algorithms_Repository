//Given a sorted array arr[] of non-repeating integers without duplicates.
//Sort the array into a wave-like array and return it. 
//In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5..... (considering the increasing lexicographical order).

#include <bits/stdc++.h>
using namespace std;

int main() {
	long int t;
	cin>>t;
	while(t>0)
	{
	    vector<long long int>v;
	    long long int n,val;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        cin>>val;
	        v.push_back(val);
	    }
	    sort(v.begin(),v.end());
	    for(int i=1;i<n;i=i+2)
	    {
	        swap(v[i],v[i-1]);
	    }
	    
	    
	    for(int i=0;i<v.size();i++)
	    cout<<v[i]<<" ";
	    cout<<"\n";
	    t--;
	}
	return 0;
}