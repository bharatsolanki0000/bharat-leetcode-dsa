class Solution {

    void dfs(vector<vector<int>>&grid, int x,int y, int value, int &ans){

        int size=grid.size();

        if(x==size-1 && y==size-1){
            ans=min(ans,value);
            return ;
        }

        grid[x][y]=1;

        //8 directions
        vector<vector<int>> dir={{0,1}, {0,-1},{1,0},{-1,0}, {1,-1},{-1,1},{1,1},{-1,-1}}; 

        for(auto d:dir){
            int tempx=x+d[0];
            int tempy=y+d[1];

            if(tempx<0 || tempy<0 || tempx>=size || tempy>=size || grid[tempx][tempy]==1){
                continue;
            }

            dfs(grid,tempx,tempy,value+1,ans);
        }
        grid[x][y]=0;

    }
public:

    int dfsSolve(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        int size=grid.size();

        if(grid[0][0]==1 || grid[size-1][size-1]==1){
            return -1;
        }

        dfs(grid,0,0,1, ans);
        
        return (ans==INT_MAX?-1:ans);
    }


    int bfsSolve(vector<vector<int>>&grid){
        
        int size=grid.size();

        if(grid[0][0]==1 || grid[size-1][size-1]==1){
            return -1;
        }

        queue<pair<int,int>>q;
        vector<vector<int>> dir={{0,1}, {0,-1},{1,0},{-1,0}, {1,-1},{-1,1},{1,1},{-1,-1}}; 
        q.push({0,0});

        grid[0][0]=1;

        int value=1;

        while(!q.empty()){

            int qsize=q.size();

            while(qsize--){

                int x=q.front().first;
                int y=q.front().second;
                q.pop();


                if(x==size-1 && y==size-1){
                   return value;
                }

                for(auto d:dir){
                    int tempx=x+d[0];
                    int tempy=y+d[1];

                    if(tempx<0 || tempy<0 || tempx>=size || tempy>=size || grid[tempx][tempy]==1){
                        continue;
                    }

                    grid[tempx][tempy]=1;
                    q.push({tempx,tempy});
                }
            }
            value++;
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        //return dfsSolve(grid);

        return bfsSolve(grid);
    }
};