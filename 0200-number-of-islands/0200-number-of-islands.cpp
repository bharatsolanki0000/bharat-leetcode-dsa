class Solution {

    void dfs(vector<vector<char>>& grid, int i , int j){ 

        int rowSize=grid.size();
        int colSize=grid[0].size();

        if(i<0 || i>=rowSize || j<0 || j>=colSize || grid[i][j]!='1'){
            return ;
        }

        grid[i][j]='0';

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);

       
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int ans=0;
        int rowSize=grid.size();
        int colSize=grid[0].size();
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){

                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
        

    }
};