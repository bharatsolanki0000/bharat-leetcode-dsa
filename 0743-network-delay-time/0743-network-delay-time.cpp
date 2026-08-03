class Solution {
public:
    typedef pair<int,int> pp;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        k=k-1;
        unordered_map<int,vector<pair<int,int>>> adj;

        for(int i=0;i<times.size();i++){
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int w=times[i][2];

            adj[u].push_back({v,w});
        }


        vector<int>dist(n,INT_MAX);
        dist[k]=0;

        priority_queue<pp,vector<pp>, greater<pp>> minHeap;
        minHeap.push({0,k});

        while(!minHeap.empty()){
            auto front=minHeap.top();
            int time=front.first;
            int node=front.second;
            minHeap.pop();

            if(time > dist[node]) continue;

            for(auto nei:adj[node]){
                int neiNode=nei.first;
                int neiTime=nei.second;

                if(time+neiTime<dist[neiNode]){
                    dist[neiNode]=time+neiTime;
                    minHeap.push({dist[neiNode], neiNode});
                }
            }
        }

      int ans = 0;

    for(int i = 0; i < n; i++){
        if(dist[i] == INT_MAX)
            return -1;

        ans = max(ans, dist[i]);
    }

    return ans;

    }
};