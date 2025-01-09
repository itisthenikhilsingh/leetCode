class Solution {
public:
bool cont(string word, string pref)
{
    for(int i=0;i<pref.length();i++)
    {
        if(word[i]!=pref[i])
        {
            return false;
        }
    }
    return true;
}
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        
        for(int i=0;i<words.size();i++)
        {
            if(cont(words[i],pref)) ans++;
        }
        return ans;
    }
};