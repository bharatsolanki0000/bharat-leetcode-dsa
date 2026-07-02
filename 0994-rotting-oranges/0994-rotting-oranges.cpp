class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int totalFresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    totalFresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        if(totalFresh==0){
            return 0;
        }

        int time=-1;
        while(!q.empty()){
            time++;

            int size=q.size();
            while(size--){
                auto rottenOrange=q.front();
                q.pop();

                int i=rottenOrange.first;
                int j=rottenOrange.second;

                vector<vector<int>> dir={{0,1},{0,-1},{-1,0},{1,0}};
                for(auto d:dir){
                    int x=i+d[0];
                    int y=j+d[1];

                    if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
                        continue;
                    }

                    if(grid[x][y]==1){
                        totalFresh--;
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
        }
        
        return totalFresh==0?time:-1;

    }
};