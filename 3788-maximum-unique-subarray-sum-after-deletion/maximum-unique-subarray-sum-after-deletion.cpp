class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> numSet;
        int ans=0;
        int maxi=INT_MIN;

        for(int i =0;i<nums.size();i++){
            int num =nums[i];
            maxi=max(num,maxi);
            if(numSet.find(num) != numSet.end()) continue;
            if(num>0){
                ans+=num;
                numSet.insert(num);
            }
        }
        if(numSet.empty()) return maxi;
        return ans;
        
    }
};