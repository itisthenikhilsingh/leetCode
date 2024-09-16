class Solution {
public:
    void solve(vector<int>nums,vector<vector<int>>&ans,vector<int>output,int index){

        if(index>=nums.size())
        {
            ans.push_back(output);
            return;
        }

        //exclude
        solve(nums,ans,output,index+1);

        //include
        int ele=nums[index];
        output.push_back(ele);
        solve(nums,ans,output,index+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        vector<int>output;
        solve(nums,ans,output,index);

        return ans;


        


        
        
    }
};