class Solution {

    bool solve(vector<vector<char>>& grid, vector<vector<bool>>& visited ,int x, int y, int parentx, int parenty){
        int rowSize=grid.size();
        int colSize=grid[0].size();

        visited[x][y]=true;

        vector<vector<int>> temp={{0,1},{0,-1},{1,0},{-1,0}};

        for(int i=0;i<4;i++){

            int tempx=x+temp[i][0];
            int tempy=y+temp[i][1];

            if(tempx<0 || tempy<0 || tempx>=rowSize || tempy>=colSize){
                continue;
            }

            if(grid[tempx][tempy]!=grid[x][y]){
                continue;
            }

            if(tempx==parentx && tempy==parenty){
                continue;
            }

            if(visited[tempx][tempy]){
                return true;
            }
            
            if(solve(grid,visited,tempx,tempy,x,y)){
                return true;
            }
        }

        return false;


    }
public:
    bool containsCycle(vector<vector<char>>& grid) {

        int rowSize=grid.size();
        int colSize=grid[0].size();

        vector<vector<bool>> visited(rowSize, vector<bool> (colSize,false));

        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){

                if(!visited[i][j]){
                    if(solve(grid, visited,i,j,-1,-1)){
                        return true;
                    }
                }
            }
        }

        return false;
                

    }
};