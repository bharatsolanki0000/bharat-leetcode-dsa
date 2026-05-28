
bool cmp(pair<int,char> &a, pair<int,char> &b){

    return a.first>b.first;

    
}
class Solution {
public:
    string frequencySort(string s) {
        
        vector<pair<int,char>> freq(128);

        for(int i=0;i<128;i++){
            freq[i].first=0;
            freq[i].second=char(i);
        }

        for(int i=0;i<s.length();i++){
            freq[s[i]].first++;
        
        }

        string ans="";

        sort(freq.begin(), freq.end(), cmp);

        for(int i=0;i<128;i++){
            if(freq[i].first>0){
                ans.append(freq[i].first, freq[i].second);
            }
        }
        return ans;
    }
};