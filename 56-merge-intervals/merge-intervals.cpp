class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size()<2) return intervals;

        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<intervals.size();i++)
        {
            if(ans.empty())
            ans.push_back(intervals[i]);

            vector<int> lastInterval=ans.back();
            vector<int> currInterval=intervals[i];

            if(lastInterval[1]>=currInterval[0])//operlaping
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else ans.push_back(intervals[i]);


        }

        return ans;
        
    }
};