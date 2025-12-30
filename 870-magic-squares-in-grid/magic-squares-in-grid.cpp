class Solution {
public:
    bool isCorrect(vector<vector<int>>& grid ,int x , int y )
    {
        if(x+2>=grid.size() || y+2>=grid[0].size() ) return false;

        int sumR[3]={0};
        int sumC[3]={0};
        set<int> s;

        for(int i=x;i<x+3; i++)
        {
            int sum=0;
            
            for(int j=y; j<y+3;j++)
            {
                if(s.count(grid[i][j])) return false ;
                if(grid[i][j]>9 || grid[i][j]<1 ) return false;
                sum=sum+grid[i][j];
                s.insert(grid[i][j]);
            }
            sumR[i-x]=sum;
            if(i>x && sumR[i-x]!=sumR[i-x-1]) return false;
        }

        for(int j=y; j<y+3;j++)
        {
            int sum =0;
            for(int i=x;i<x+3; i++)
            {
                sum= sum+grid[i][j]; 
            }
            sumC[j-y]=sum;
            if(j>y && sumC[j-y]!=sumC[j-y-1]) return false;
        }

        if(sumR[0]!=sumC[0]) return false;

        int LD= grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2];
        int RD= grid[x+2][y]+grid[x+1][y+1] + grid[x][y+2];

        if(LD != RD ) return false;

        return LD == sumC[0];
        
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int ans=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(isCorrect(grid,i,j)) ans++;

            }
        }
        return ans;
        
    }
};