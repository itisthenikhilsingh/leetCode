class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int strSize = strs[0].size();

        for(int i=0;i<strSize;i++)
        {
            for(int j=0;j<strs.size()-1;j++)
            {
                if(strs[j][i]>strs[j+1][i]){
                    ans++;
                    break;
                }

            }
        }
        return ans;
        
    }
};