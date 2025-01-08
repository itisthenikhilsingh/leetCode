class Solution {
public:
    int maxrob(vector<int>& nums,int i,vector<int>& dp)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        int rob1=nums[i]+maxrob(nums,i+2,dp);
        int rob2=maxrob(nums,i+1,dp);

        dp[i]= max(rob1,rob2);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int ans=maxrob(nums,0,dp);
        return ans;
        
        
    }
};