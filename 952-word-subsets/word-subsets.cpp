class Solution {
public:
    bool isSub(vector<int> frq,vector<int> maxFrq)
    {
        for(int i=0;i<26;i++)
        {
            if(frq[i]<maxFrq[i])
            {
                return false;
            }

        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {


        vector<string> ans;

        vector<int> maxFrq (26,0);
        for(int i=0;i<words2.size();i++)
        {
            vector<int> frq (26,0);

            for(auto ch:words2[i])
            {
                frq[ch-'a']++;
            }

            for(int j=0;j<26;j++)
            {
                maxFrq[j]=max(maxFrq[j],frq[j]);
            }
        }
        for(int i=0;i<words1.size();i++)
        {
            vector<int> frq (26,0);
            for(auto ch:words1[i])
            {
                frq[ch-'a']++;
            }

            if(isSub(frq,maxFrq))
            {
                ans.push_back(words1[i]);
            }
        }
        return ans;
        
    }
};