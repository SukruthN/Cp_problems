class Solution {
public:
    int maxArea(vector<int>& height) {
        int i,j;
        i=0;
        j=(int)height.size()-1;
        int res=INT_MIN;
        int ans=0;
       while(i!=j)
       {
           ans=min(height[i],height[j])*(j-i);
           res=max(res,ans);
           if(height[i]<height[j])
           {
               i++;
           }
           else
               j--;
       }
        
        if(res!=INT_MIN)
            return res;
        else
            return 0;
    }
};