class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if(s.size()<k) return false;
        vector<int> frq(26,0);

        for(auto ch:s)
        {
            frq[ch-'a']++;
        }
        ;
        int odd=0;
        for(int i=0;i<26;i++)
        {
            if(frq[i]%2==1)
            {
                odd++;
            }
        }

        

        if(odd>k) return false;

        return true;
        
    }
};