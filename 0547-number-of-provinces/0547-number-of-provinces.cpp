class Solution {

    void bruteDfs(unordered_map<int,vector<int>>&adj,int node, vector<int> &visited){

        visited[node]=1;

        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                bruteDfs(adj,neighbor,visited);
            }
        }
    }

    int brute(vector<vector<int>>& isConnected) {
        
            unordered_map<int,vector<int>> adj;

            for(int i=0;i<isConnected.size();i++){
                int u=i;

                for(int j=0;j<isConnected[0].size();j++){
                    int v=j;

                    if(isConnected[u][v]==1){
                        adj[u].push_back(v);
                    }
                }
            }

            int V=isConnected.size();
            vector<int>visited(V,0);

            int ans=0;
            for(int i=0;i<V;i++){
                if(!visited[i]){
                    bruteDfs(adj,i,visited);
                    ans++;
                }
            }
        return ans;    
    }

    void dfs(vector<vector<int>>& isConnected, int u, vector<int>&visited){
        visited[u]=1;

        for(int v=0;v<isConnected.size();v++){
            if(isConnected[u][v]==1 && !visited[v]){
                dfs(isConnected,v,visited);
            }
        }
    }

    int optimal(vector<vector<int>>& isConnected){
        
        vector<int>visited(isConnected.size(),0);
        int ans=0;
        for(int u=0;u<isConnected.size();u++){
            if(!visited[u]){
                dfs(isConnected,u,visited);
                ans++;
            }
        }
        return ans;
    }

    int bfs(vector<vector<int>>& isConnected){


        int ans=0;
        vector<int>visited(isConnected.size(),0);

        for(int u=0;u<isConnected.size();u++){
            
            queue<int>q;
            if(!visited[u]){
                visited[u]=1;
                q.push(u);
                ans++;
            
            while(!q.empty()){
                int u=q.front();
                q.pop();

                for(int v=0;v<isConnected.size();v++){
                    if(isConnected[u][v]==1 && !visited[v]){
                        visited[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        }
        return ans;

        
    }

   

    
class dsu{
    vector<int>parent,size;

    public:

    int components;

    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        components = n;

        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        int root = node;
        while(root != parent[root]){
            root = parent[root];
        }

        while(node != root){
            int next = parent[node];
            parent[node] = root;
            node = next;
        }

        return root;
    }

    bool unionBySize(int u , int v){

        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv){
            return false;   // already connected -> forming a cycle
        }
        else if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }

        components--;
        return true;
    }


};


int dsuSolve(vector<vector<int>>&isConnected){

    dsu obj(isConnected.size());

    for(int i=0;i<isConnected.size();i++){
        for(int j=0;j<isConnected[0].size();j++){

            if(i!=j && isConnected[i][j]==1){

                obj.unionBySize(i,j);


                
            }
        }
    }

    return obj.components;
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //return brute(isConnected); 

       // return optimal(isConnected);

      // return bfs(isConnected);

      return dsuSolve(isConnected);
    }
};