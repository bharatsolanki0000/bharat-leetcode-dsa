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

    
    bool solve2(vector<int>& arr, int index){ 
        int size=arr.size();

        if(index<0 || index>=size || arr[index]<0){
            return false;
        }

        if(arr[index]==0){
            return true;
        }

        arr[index]*=-1;
        int next=solve2(arr, index+arr[index]);
        int prev=solve2(arr, index-arr[index]);

        return next || prev;
    }
public:
    bool canReach(vector<int>& arr, int start) {

        // vector<int> visited(arr.size() ,0);
        // visited[start]=1;
        // return solve(arr,start, visited);

        // using arr also as a viistied by putting -1 as viisted
        return solve2(arr,start);
    }
};