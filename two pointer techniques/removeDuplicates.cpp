//Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n=nums.size();
    if(n<3)
		return n;
    int left=2;
    for(int right=2;right<n;right++)
    {
        if(nums[left-2]!=nums[right])
        nums[left++]=nums[right];
    }
    return left;
}

int main()
{
	int size;
	cout<<"Enter size of array :";
	cin>>size;
	
	cout<<"Enter array elements :";
	vector<int>array(size);
	
	for(int i=0;i<size;i++)
	cin>>array[i];
	
	size=removeDuplicates(array);
	cout<<"Array after removing duplicated elements from the array with duplicate elements at most two\n:";
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
	return 0;
}
