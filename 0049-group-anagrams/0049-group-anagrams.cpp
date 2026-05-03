class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<int>> mp;

        vector<int> temp(26,0);

        for(int i=0;i<strs.size();i++){
            string element=strs[i];
            sort(element.begin(), element.end());
            mp[element].push_back(i);
            
        }

        vector<vector<string>> ans;

        for(auto word: mp){
            vector<string> temper;
            for(auto index: word.second){
                temper.push_back(strs[index]);
            }
            ans.push_back(temper);
        }

        return ans;
    }
};