class Solution {
public:
    void dfs(int node ,vector<vector<int>>& isConnected, vector<int>& isVisted)
    {
        for(int i=0;i<isConnected.size();i++)
        {
            if(isConnected[node][i]==1 && !isVisted[i]) {
                isVisted[i]=1;
                dfs(i , isConnected ,isVisted);
                }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int nodes= isConnected.size();
        int ans=0;

        vector<int> isVisted(nodes,0);

        for(int i=0;i<nodes;i++)
        {
            if(isVisted[i]==0)
            {
                ans++;
                dfs(i , isConnected ,isVisted);

            }
            else continue;
        }
        return ans;
    }
};