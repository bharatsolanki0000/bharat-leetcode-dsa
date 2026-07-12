class Solution {

    vector<int> solve1(vector<int>& arr) {

        
        map<int,vector<int>> mp;
        int size=arr.size();
        vector<int>ans(size,0);

        for(int i=0;i<size;i++){
            mp[arr[i]].push_back(i);
        }

        int rank=1;

        for(auto temp:mp){
            for(auto t:temp.second){
                ans[t]=rank;
            }
            rank++;
        }

        return ans;

    }

    vector<int> solve2(vector<int>& arr) {

        int size=arr.size();
        vector<int>ans=arr;

        unordered_map<int,int> mp;
        //           num  rank

        sort(ans.begin(), ans.end());

        int rank=1;
        for(int i=0;i<size;i++){
            
            if(!mp.count(ans[i])){
                mp[ans[i]]=rank;
                rank++;
            }
        }
        

        for(int i=0;i<size;i++){
            arr[i]=mp[arr[i]];
        }

        return arr;

    }
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        //return solve1(arr);

        return solve2(arr);

    }
};
