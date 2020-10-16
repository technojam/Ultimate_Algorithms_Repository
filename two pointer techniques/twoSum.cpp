
// Given an array of integers that is already sorted in ascending order, 
//find two numbers such that they add up to a specific target number.
  	#include<bits/stdc++.h>
  	using namespace std;
  	
	vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int n=numbers.size();
        int left=0;
        int right=n-1;
        while(left<right)
        {
            if(numbers[left]+numbers[right]==target)
            {
                ans.push_back(left);
                ans.push_back(right);
                break;
            }
            else
            {
                if(numbers[left]+numbers[right]<target)
                {
                    left++;
                }
                else
                {
                    right--;    
                }
            }
        }
        return ans;
    }
    int main()
    {
    	int size;
    	cout<<"Enter Size of Array: ";
    	cin>>size;
    	vector<int>array(size);
    	
		cout<<"Enter array elements(must be sorted) : ";
    	
		for(int i=0;i<size;i++)
    	cin>>array[i];
    	
    	int target;
    	cout<<"Enter target :";
    	cin>>target;
    	vector<int>result=twoSum(array,target);
    	cout<<"Result: ";
    	cout<<result.size();
		for(int i=0;i<result.size();i++)
    	cout<<result[i]<<" ";
    	
		if(result.size()==0)
    	{
    		cout<<"No results as no two elements found adding to target!!!";
		}
    	
    	return 0;
	}
