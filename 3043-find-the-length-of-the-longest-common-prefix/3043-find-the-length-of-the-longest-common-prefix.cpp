class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_map<string,int> mp;
        int ans=0;

        for(int i=0;i<arr1.size();i++){

            string first=to_string(arr1[i]);

            int j=0;
            string temp="";

            while(j<first.length()){
                temp.push_back(first[j]);
                mp[temp]=j+1;
                j++;
            }
        }

        for(int j=0;j<arr2.size();j++){

            string second=to_string(arr2[j]);
            string temp="";
            int k=0;
            while(k<second.length()){

                temp.push_back(second[k]);
                if(mp.count(temp)){
                    ans=max(ans,mp[temp]);
                }
                else{
                    break;
                }

                k++;
            }

        }
        return ans;
    }
};