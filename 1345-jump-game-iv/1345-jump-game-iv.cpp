class Solution {

    int solve(vector<int>& arr, int index, vector<int>& visited){ 
        int size=arr.size();

        if(visited[index]){
            return INT_MAX;
        }


        if(index==size-1){
            return 0;
        }

        int ans=INT_MAX;

        
        //left

        if(index-1 >=0 && !visited[index-1]){

            visited[index]=1;
            int left=solve(arr, index-1, visited);
            if(left!=INT_MAX){
                ans=min(ans, 1+left);
            }
            visited[index]=0;
        }
        


        //right
         if(index+1 <size && !visited[index+1]){

            visited[index]=1;
            int right=solve(arr, index+1, visited);
            if(right!=INT_MAX){
                ans=min(ans, 1+right);
            }
            visited[index]=0;
         }



        //same element
        int same=INT_MAX;
        for(int j=index+1;j<size;j++){
            if(arr[index]==arr[j]){
                same=min(same, solve(arr,j, visited));
            }
        }


        if(same!=INT_MAX){
            ans=min(ans, 1+same);
        }

        
        return ans;
        

    }


    int bfs(vector<int>& arr){
       
       
       unordered_map<int,vector<int>>mp;


       for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
       }

        vector<int> visited(arr.size(), 0);
       queue<int>q;
       q.push(0);
       visited[0]=1;

        int steps=0;

       while(!q.empty()){

            int size=q.size();
            while(size--){

                int index=q.front();
                q.pop();


                if(index==arr.size()-1){
                    return steps;
                }

                if(index-1 >=0 && !visited[index-1]){
                    visited[index-1]=1;
                    q.push(index-1);
                }


                if(index+1 < arr.size() && !visited[index+1]){
                    visited[index+1]=1;
                    q.push(index+1);
                }


                for(auto j:mp[arr[index]]){
                    if(!visited[j]){
                        visited[j]=1;
                        q.push(j);
                    }
                }

                   mp[arr[index]].clear();



            }
            steps++;

       }

       return steps ;

        
    }

public:
    int minJumps(vector<int>& arr) {
        
        int size=arr.size();
        vector<int> visited(size,0);

        if(arr.size()==1){
            return 0;
        }

        if(arr[0]==arr[size-1]){
            return 1;
        }

        //tried recursion but TLE
        // return solve(arr, 0, visited);

        return bfs(arr);

    }
};