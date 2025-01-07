class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0];
        int sum=nums[0];

        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)
            {sum= sum+nums[i];}
            maxSum=max(sum,maxSum);

            if(sum<0)
            {sum=0;}
        }
        return maxSum;
        
    }
};