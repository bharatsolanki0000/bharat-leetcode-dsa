class Solution {

    void dfs(unordered_map<int,vector<pair<int,int>>>&adj, int node, int &dst, int k, unordered_map<int,int>&visited,
    int price, int &ans){

        if(k<-1){
            return ;
        }

        if(node==dst){
            ans=min(ans,price);
            return ;
        }

        visited[node]=1;

        for(auto nei:adj[node]){

            int neiNode=nei.first;
            int neiPrice=nei.second;

            if(!visited.count(neiNode)){
                dfs(adj,neiNode,dst,k-1,visited,price+neiPrice,ans);
            }
        }
        
        visited.erase(node);
        
    }
public:

    int dfsSolve(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            unordered_map<int,vector<pair<int,int>>> adj;
            unordered_map<int,int>visited;

            for(auto f:flights){
                int u=f[0];
                int v=f[1];
                int w=f[2];

                adj[u].push_back({v,w});
            }

            int ans=INT_MAX;
            //dfs
            dfs(adj,src,dst,k,visited, 0, ans);

            return (ans==INT_MAX?-1:ans);
            
        }

    int bfsSolve(int n, vector<vector<int>>& flights, int src, int dst, int k){

        unordered_map<int,vector<pair<int,int>>> adj;

         for(auto f:flights){
            int u=f[0];
            int v=f[1];
            int w=f[2];

            adj[u].push_back({v,w});
        }
        
        vector<int>dist(n,INT_MAX);
      queue<pair<int,pair<int,int>>>q;


        dist[src]=0;
        q.push({0,{src,0}});

        
        while(!q.empty()){
                
            auto top=q.front();
            int stops=top.first;
            int node=top.second.first;
            int cost=top.second.second;
            q.pop();

            if(stops>k) continue;


                for(auto nei:adj[node]){
                    int neiNode=nei.first;
                    int neiWt=nei.second;


                    if(cost+neiWt<dist[neiNode] && stops<=k){
                        dist[neiNode]=cost+neiWt;

                        q.push({stops+1,{ neiNode,dist[neiNode]}});
                    }
                }
            
        }

        if(dist[dst]==INT_MAX){
            return -1;
        }

        return dist[dst];

    }  

    typedef pair<int,int> pp;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //return dfsSolve(n,flights,src,dst,k);

        return bfsSolve(n,flights,src,dst,k);
    }
};