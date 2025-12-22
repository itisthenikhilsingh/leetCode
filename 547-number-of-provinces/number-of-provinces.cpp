class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& isVisited)
    {
        // Mark the current node as visited as soon as we enter DFS
        isVisited[node] = 1;

        // Traverse all possible connections of the current node
        for (int i = 0; i < isConnected.size(); i++)
        {
            // If there is a direct connection and the node is not visited
            if (isConnected[node][i] == 1 && !isVisited[i])
            {
                // Recursively visit the connected node
                dfs(i, isConnected, isVisited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int nodes = isConnected.size();
        int provinces = 0;

        // Visited array to keep track of visited cities
        vector<int> isVisited(nodes, 0);

        // Check each node
        for (int i = 0; i < nodes; i++)
        {
            // If the node is not visited, it starts a new province
            if (!isVisited[i])
            {
                provinces++;
                dfs(i, isConnected, isVisited);
            }
        }

        return provinces;
    }
};
