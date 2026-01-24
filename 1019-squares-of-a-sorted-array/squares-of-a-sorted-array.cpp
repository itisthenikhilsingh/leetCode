class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);

        for (int i=0;i<n;i++)
        {
            nums[i]= nums[i]*nums[i];
        }
        
        int i=0;
        int j=n-1;
        int k=n-1;

        while(i<=j)
        {
            if(nums[i]>=nums[j]) {ans[k]=nums[i]; i++;}
            else {ans[k]=nums[j]; j--;}
            k--;
        }
        return ans;
    }
};