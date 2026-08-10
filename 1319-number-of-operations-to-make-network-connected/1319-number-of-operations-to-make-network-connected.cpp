class Solution {
public:

    vector<int>parent,size;

    int findParent(int node){
        if(node==parent[node]){
            return node;
        }

        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv) return ;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }


    int makeConnected(int n, vector<vector<int>>& connections) {
         int V=n;
         int E=connections.size();

         if(V-1>E){
            return -1;
         }

         parent.resize(V);
         size.resize(V,1);

         for(int i=0;i<V;i++){
            parent[i]=i;
         }

        int extraCables=0;
        int components=n;

        for(auto c:connections){
            int u=c[0];
            int v=c[1];

            if(findParent(u)==findParent(v)){
                extraCables++;
            }
            else{
                components--;
                unionBySize(u,v);
            }
        }

        if(components>extraCables+1){
            return -1;
        }

        return components-1;
        

    }
};