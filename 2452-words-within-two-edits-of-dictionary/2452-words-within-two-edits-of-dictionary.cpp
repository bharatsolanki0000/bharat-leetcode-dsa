class Solution {

    bool check(string &first, string &second){
        int count=2;

        for(int i=0;i<first.length();i++){

            if(first[i]!=second[i]){
                if(count){
                    count--;
                    continue;
                }
                else{
                    return false;
                }

            }
        }
        return true;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
         
         vector<string> ans;
         for(int i=0;i<queries.size();i++){
            string first=queries[i];


            for(int j=0;j<dictionary.size();j++){
                string second=dictionary[j];

                if(check(first, second)){
                    ans.push_back(first);
                    break;
                }
            }
         }
         return ans;
    }
};