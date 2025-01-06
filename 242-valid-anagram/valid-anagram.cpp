class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> hash1;

        for(auto i:s)
        {
            hash1[i]++;
        }
        map<char,int> hash2;

        for(auto i:t)
        {
            hash2[i]++;
        }
        return hash1==hash2;
        
        
        
    }
};