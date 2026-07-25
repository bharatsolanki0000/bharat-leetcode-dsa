class Solution {

    bool topoSort(int V,unordered_map<int,vector<int>>&adj){

        vector<int>indegree(V,0);
        queue<int>q;


        for(auto it:adj){
            for(auto temp:it.second){
                indegree[temp]++;
            }

        }

        for(int i=0;i<indegree.size();i++){
            
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            count++;

            for(auto nei:adj[node]){

                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }

        return (count==V);
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<prerequisites.size();i++){

            int u=prerequisites[i][1];
            int v=prerequisites[i][0];

            adj[u].push_back(v);
        }

        return topoSort(numCourses,adj);
    }
};