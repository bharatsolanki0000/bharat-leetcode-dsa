class Solution {

    bool solve(vector<int>&arr, int index, vector<int>& visited){

        int size=arr.size();
        if(arr[index]==0){
            return true;
        }


        int ans=false;
        //arr +i
        int nextIndex=index+arr[index];
        if(nextIndex<size){
         if(!visited[nextIndex]){
                visited[nextIndex]=1;
                if(solve(arr,nextIndex,visited)){
                     return true;
                }
               
            }
        }



        //arr - i
        int prevIndex=index-arr[index];
        if(prevIndex>=0){
            if(!visited[prevIndex]){
                visited[prevIndex]=1;
                if(solve(arr,prevIndex,visited)){
                     return true;
                }
               
            }
        }

        return false;
    }

    
    bool dfs(vector<int>& arr, int index){ 
        int size=arr.size();

        if(index<0 || index>=size || arr[index]<0){
            return false;
        }

        if(arr[index]==0){
            return true;
        }

        int newIndex=arr[index];
        arr[index]*=-1;

        int next=dfs(arr, index+newIndex);
        int prev=dfs(arr, index-newIndex);

        return next || prev;
    }


    bool bfs(vector<int>& arr, int start){

        queue<int>q;
        q.push(start);


        while(!q.empty()){

            int size=q.size();

            while(size--){

                int index=q.front();
                q.pop();

                if(index<0 || index>=arr.size() || arr[index]<0){
                    continue;
                }


                if(arr[index]==0){
                    return true;
                }

                int newIndex=arr[index];
                arr[index]*=-1;


                q.push(index+newIndex);
                q.push(index-newIndex);
                
            }
            
        }

        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {

        vector<int> visited(arr.size() ,0);
        visited[start]=1;
        return solve(arr,start, visited);

       
        return dfs(arr,start);

        return bfs(arr, start);
    }
};