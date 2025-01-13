class Solution {
public:
    int minimumLength(string s) {
       vector<int> frq(26,0);
       int ans=0;
       for(char ch:s)
       {
        frq[ch-'a']++;
       }
       for(int fr:frq)
       {
        if(fr==0) continue;
        if(fr%2==0){
            ans+=2;
        } else ans+=1;
       }
       return ans;
    }
    
};