class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for(int i=0;i<nums.size();i++)
        {
           int a = nums[i];
            int need= target-a;
            if(mpp.find(need)!=mpp.end())
            {
                return {i,mpp[need]};
            }
            mpp[a]=i;
        }
        return {-1,-1};
        
    }
};