class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int target =0;
        if(n<3) return {};
        vector<vector<int>> ans;

        for(int a=0;a<n-2;a++)
        {
            int i=a+1;
            int j=n-1;
            if(a > 0 && nums[a] == nums[a-1]) continue;
            
            while(i<j)
            {
                
                int sum =nums[i]+nums[a]+nums[j];
                if(sum==0) {ans.push_back({nums[a],nums[i],nums[j]});
                
                while(i < j && nums[i] == nums[i+1]) i++;
                while(i < j && nums[j] == nums[j-1]) j--;
                i++;j--;
                }
                else if(sum<0) {i++;}
                else {j--;}
                
            }
        }
        return ans;
    }
};