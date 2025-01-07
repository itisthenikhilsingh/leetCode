class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int no0=0;
        int pr=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {no0++;
            continue;}
            pr*=nums[i];
        }
        if(no0>1)
        {
            vector<int> vec(nums.size(), 0);
            return vec;
             
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0 && no0==0) nums[i]=pr/nums[i];
            else if(nums[i]==0 && no0!=0) nums[i]=pr;
            else nums[i]=0;
            
        }
        return nums;
        
    }
};