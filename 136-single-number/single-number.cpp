class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
             mpp[nums[i]]++;
        }
        for(auto &[key,value]:mpp)
        {
            if(value==1)
            {
                return key;
            }
        }
        return -1;
        
    }
};