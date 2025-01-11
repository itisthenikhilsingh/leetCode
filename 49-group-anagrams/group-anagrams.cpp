class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;

        for(int i=0;i<strs.size();i++)
        {
            string key=strs[i];
            sort(key.begin(),key.end());

            mpp[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto s:mpp)
        {
            ans.push_back(s.second);
        }
        return ans;

        
    }
};