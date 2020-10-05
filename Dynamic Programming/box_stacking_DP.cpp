/*
You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. You task is to complete the function maxHeight which returns the height of the highest possible stack so formed.

Input:
The first line of input contains an integer T denoting the number of test cases then T test cases follow. Each test case contains an integer N denoting the total no of boxes available. In the next line are 3*N space separated values denoting the height, width and length of the N boxes.

Output:
For each test case in a new line output will be the highest possible stack height which could be formed.
*/
int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    int size=n;
    if(n==0) return 0;
    vector<vector<int>> res;
    for(int i=0;i<size;i++)
    {
        int h=height[i];
        int w=width[i];
        int l=length[i];
        res.push_back({h*w,h,w,l,h});
        res.push_back({h*l,h,l,w,h});
        res.push_back({l*h,l,h,w,h});
        res.push_back({l*w,l,w,h,h});
        res.push_back({w*l,w,l,h,h});
        res.push_back({w*h,w,h,l,h});
    }
    sort(res.begin(),res.end(),[&](vector<int>&a,vector<int>&b)
    {
       if(a[0]>b[0]) return 1;
       else
        return 0;
    });
    vector<int> v,temp;
    for(auto itr : res)
    {
        //for(auto itr2: itr)
        //cout<<itr2<<" ";
        //cout<<"\n";
        temp.push_back(itr[3]);
        v.push_back(itr[3]);
    }
    for(int i=1;i<(6*size);i++){
        for(int j=0;j<i;j++)
        {
            if(res[j][0]>res[i][0] && res[j][1]>res[i][1] && res[j][2]>res[i][2])
            temp[i]=max(temp[i],temp[j]+v[i]);
        }
    }
    int max_val=INT_MIN;
    for(auto itr : temp)
    max_val=max(max_val,itr);
    return max_val;
}
