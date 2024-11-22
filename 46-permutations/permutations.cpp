class Solution {
public:
    void recPer(vector<int>& nums,vector<int> &ds,vector<vector<int>> &ans,vector<int> &freq)
    {
        //base case is when the temp array (ds) size is equal to the size of the nums array
        if(nums.size()==ds.size())
        {
            ans.push_back(ds);
            return;
        }
        //going to each element to in the array
        for(int i=0;i<nums.size();i++)
        {
        //choosing the element to take in the temp array if its frequeny is not zero
        if(!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i]=1;
             recPer(nums,ds,ans,freq);
             freq[i]=0;
             ds.pop_back();

        }
        }

    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        vector<int> freq(nums.size(),0);

        recPer(nums,ds,ans,freq);
        return ans;
        
    }
};