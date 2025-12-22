class Solution {
public:
    void dfs(int node ,vector<vector<int>>& isConnected, vector<int>& isVisted)
    {
        //base conditon that if the node is alredy visited then just skip the part

        //lopping through the all the connection of the node ini 2d array
        for(int i=0;i<isConnected.size();i++)
        {
            //if we find the connection and that is not visted 
            if(isConnected[node][i]==1 && !isVisted[i]) {
                
                // the array is updated as we had alredy visited it
                isVisted[i]=1;

                // now visting all connection of the connected node 
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