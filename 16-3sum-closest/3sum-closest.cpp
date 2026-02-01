class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        int diff =0;
        int n = nums.size();
        pair <int , int> pr;

        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k = n-1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                int subtract = abs(sum-target);
                if(subtract<abs(closest - target)) closest=sum;

                if(sum==target) return target;

                else if(sum<target) j++;
                else k--;

            }
        }
        return closest;
    }
};