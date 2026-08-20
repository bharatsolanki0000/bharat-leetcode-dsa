class Solution {
public:

class dsu{
    vector<int>parent,size;
    public:

    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=1;i<=n;i++){
            parent[i]=i;
        }

    }

    int findParent(int node){
        int root=node;

        while(root!=parent[root]){
            root=parent[root];
        }

        while(node!=root){
            int next=parent[node];
            parent[node]=root;
            node=next;
        }

        return root;
    }

    bool unionBySize(int u, int v){
        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv){
            return true;
            //already connected
        }
        
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }

        return false;
    }
};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        vector<int>ans(2,-1);

        dsu obj(n);

        for(auto e:edges){
            int u=e[0];
            int v=e[1];

            if(obj.unionBySize(u,v)){
                //true means already connected

                ans[0]=u;
                ans[1]=v;
            }
            
        }

        return ans;
    }
};