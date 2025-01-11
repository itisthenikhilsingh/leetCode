class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inte) {
        vector<vector<int>> ans;
        sort(inte.begin(),inte.end());
        int k=0;

        for(int i=0;i<inte.size();i++)
        {
            if(inte[k][1]>=inte[i][0])
            {
                inte[k][1] = max(inte[k][1],inte[i][1]);
            }
            else {
                k++;
                inte[k]=inte[i];
            }

        }
         inte.resize(k+1);
         return inte;
        
    }
};