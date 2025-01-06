class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        map<char,int> hash;
        for(auto i:s)
        {
            hash[i]++;
        }
        for(auto i:t)
        {
            hash[i]--;
            if( hash[i]<0) return false;
        }
        return true;   
    }
};