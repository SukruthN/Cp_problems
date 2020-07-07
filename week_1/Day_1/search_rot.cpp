class Solution {
public:
    
    int rot(vector<int>a)
    {
        int s=0;
        int e=(int)a.size()-1;
        int l=a[e];
        int m=(s+e)/2;
        while(s<=e)
        {
            if(a[m]>l)
                s=m+1;
            else if(a[m]<l)
                e=m-1;
            else
                break;
             m=(s+e)/2;
            
        }
        return m;
    }
    
    int left(vector<int>a,int s,int e,int t)
    {
        int ans=-1;
        while(s<=e)
        {
            int m=(s+e)/2;
            if(a[m]==t)
            {
                ans=m;
                break;
            }
            else if(a[m]>t)
            {
                e=m-1;
            }
            else
                s=m+1;
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
        {
            return -1;
        }
        int r=rot(nums);
        // cout<<r<<endl;
        // int l,f;
        int l=left(nums,0,r,target);
        int f=left(nums,r+1,nums.size()-1,target);
        if(nums[r]==target)
            return r;
        if(l==-1 && f==-1)
            return -1;
        else
        {
            if(l!=-1)
            {
                return l;
            }
            else
                return f;
        }
        
    }
};