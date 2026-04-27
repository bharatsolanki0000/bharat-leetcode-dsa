class Solution {

    bool solve(vector<vector<int>>& grid,unordered_map<int,vector<vector<int>>> &mp, int x, int y, vector<vector<int>>&visited){

        int rowSize=grid.size();
        int colSize=grid[0].size();

        if(x==rowSize-1 && y==colSize-1){
            return true;
        }

        visited[x][y]=1;

        for(auto neighbors: mp[grid[x][y]]){

            int tempx=x+neighbors[0];
            int tempy=y+neighbors[1];

            if(tempx<0 || tempy<0 || tempx>=rowSize || tempy>=colSize || visited[tempx][tempy]){
                continue;
            }

            //if we can backtrake then path exists

            for(auto dir: mp[grid[tempx][tempy]]){

                int tempoldx=dir[0]+tempx;
                int tempoldy=dir[1]+tempy;

                if(tempoldx==x && tempoldy==y){
                    if(solve(grid, mp,tempx, tempy,visited)){
                        return true;
                    }
                }
            }
        }

        return false;

    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
          int rowSize=grid.size();
        int colSize=grid[0].size();
        
        unordered_map<int,vector<vector<int>>> mp={
            
            {},
            {1, {{0,-1},{0,1}}},
            {2, {{-1,0},{1,0}}},
            {3, {{0,-1},{1,0}}},
            {4, {{0,1},{1,0}}},
            {5, {{-1,0},{0,-1}}},
            {6, {{0,1},{-1,0}}},
        };

        vector<vector<int>> visited(rowSize, vector<int> (colSize,0));

        return solve(grid, mp,0,0,visited);
    }
};