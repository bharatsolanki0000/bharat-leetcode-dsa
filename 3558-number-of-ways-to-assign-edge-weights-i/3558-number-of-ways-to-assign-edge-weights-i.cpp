class Solution {

    int findMaxDepth(unordered_map<int,vector<int>> & adj, int node){

        int maxDepth=0;

        for(auto neighbors: adj[node]){
            maxDepth=max(maxDepth, findMaxDepth(adj,neighbors)+1);
        }
        return maxDepth;
    }

   long long findPower(long long x, long long n) {

    if (n == 0) {
        return 1;
    }

    long long half = findPower(x, n / 2);

    long long ans = (half * half) % MOD;

    if (n & 1) {
        ans = (ans * x) % MOD;
    }

    return ans;
}

public:
    int MOD=1e9+7;
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
        }

        int root=1;
        int maxDepth=findMaxDepth(adj,root);

        // //total combinations of 1 and 2 for maxDepth 
        // int ans=findPower(2,maxDepth);

        // //even and odd possiblitieis are equal so ans/2
        // return ans/2;


        // or we can do (2^maxDepth)/2 equal to 2^(maxDepth-1)
        return findPower(2, maxDepth-1);

    }
};