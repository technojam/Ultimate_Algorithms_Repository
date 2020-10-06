// not complete
// Time complexity : O(n^2)
#include<bits/stdc++.h>
using namespace std;
#define loop1(size) for(int i=0;i<size;i++)
/*
int fun1(vector<pair<int,int> ,int> v,int size)
{
		int max_len=0;
		int val1,val2;
		vector<pair<int,int> ,int>:: iterator itr;
		vector<int> temp;
		for(int i=0;i<v.size();i++)
			temp[i]=v[i].second;
		for(int i=1;i<size;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(v[j].first.first<v[i].first.second)
				{
					if(temp[j]+v[i].second>temp[i])
						temp[i]=temp[j]+v[i].second;
				}
			}
		}
		int max_val=INT_MIN;
		loop1(temp.size())
		{
			if(temp[i]>max_val)
				max_val=temp[i];
		}
		return max_val;
}
*/
int main()
{
		int size;
		cout<<"ENTER THE SIZE :";
		cin>>size;
		vector<pair<pair<int,int>,int> > v;
		int val1,val2,val3;
		loop1(size)
		{
			cout<<i<<" : \n";
			cout<<"ENTER THE START TIME :";
			cin>>val1;
			cout<<"ENTER THE END TIME :";
			cin>>val2;
			cout<<"ENTER THE VALUE :";
			cin>>val3;
			v.push_back(make_pair(make_pair(val2,val1),val3));
		}
		sort(v.begin(),v.end());
		fun1(v,size);
		int in;
		cin>>in;
}
