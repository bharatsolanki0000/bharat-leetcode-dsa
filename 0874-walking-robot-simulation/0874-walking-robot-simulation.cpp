class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        set<pair<int,int>> obs;
        
        for(auto o: obstacles){
            obs.insert({o[0], o[1]});
        }

        int x=0;
        int y=0;

        int maxDist=0;
        

        char dir='N';
        for(int i=0;i<commands.size();i++){

            if(commands[i]==-1){
                if(dir=='N'){
                    dir='E';
                }
                else if(dir=='E'){
                    dir='S';
                }
                else if(dir=='S'){
                    dir='W';
                }
                else{
                    dir='N';
                }
            }
            else if(commands[i]==-2){
                if(dir=='N'){
                    dir='W';
                }
                else if(dir=='E'){
                    dir='N';
                }
                else if(dir=='S'){
                    dir='E';
                }
                else{
                    dir='S';
                }
            }
            else{
                
                int steps=commands[i];

                for(int step=0;step<steps;step++){

                    int nx=x;
                    int ny=y;

                    if(dir=='N'){
                    ny++;
                    }
                    else if(dir=='E'){
                        nx++;
                    }
                    else if(dir=='S'){
                        ny--;
                    }
                    else{
                        nx--;
                    }

                    if(obs.count({nx,ny})){
                        break;
                    }
                    x=nx;
                    y=ny;

                }
             
            }
            maxDist=max(maxDist, x*x+ y*y);
        }

        return maxDist;    
    }
};