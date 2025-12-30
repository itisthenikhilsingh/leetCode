class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
         vector<vector<int>> vis(rows, vector<int>(cols, 0));
         int fresh=0;
         int t=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1) fresh++ ;
            }
        }
        // doing operation till the queue is not empty
        while(!q.empty()){

            auto p = q.front();
q.pop();

int x = p.first.first;
int y = p.first.second;
int time = p.second;
            t=max(t,time);

            int drow[]={-1,0,1,0};
            int dcol[]={0,-1,0,1};

            for(int i=0;i<4;i++)
            {
                int nx=x+drow[i];
                int ny=y+dcol[i];

                if( nx<grid.size() && nx>=0 && ny>=0 && ny<grid[0].size() && vis[nx][ny]!=2 && grid[nx][ny]==1) 
                {
                    vis[nx][ny]=2;
                    fresh--;

                    q.push({{nx,ny},time+1});

                }
            }
        }
        if(fresh>0) return -1;
        
        return t;

       
        
    }
};