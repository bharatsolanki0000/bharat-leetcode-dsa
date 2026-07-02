class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        int oldColor=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;

        if(color==oldColor){
            return image;
        }

        while(!q.empty()){
            int size=q.size();

            while(size--){
                auto tile=q.front();
                q.pop();

                int i=tile.first;
                int j=tile.second;

                for(auto d:dir){
                    int x=i+d[0];
                    int y=j+d[1];

                    if(x<0 || y<0 || x>=image.size() || y>=image[0].size() || image[x][y]!=oldColor){
                        continue;
                    }

                    image[x][y]=color;
                    q.push({x,y});
                }
                
            }
        }

        return image;
    }
};