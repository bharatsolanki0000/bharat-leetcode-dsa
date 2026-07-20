class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;

        for(auto word:wordList){
            mp[word]=1;
        }

        if(!mp.count(endWord)){
            return 0;
        }

        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            auto word=q.front().first;
            int steps=q.front().second;
            q.pop();

            //check for every char in word
            for(int i=0;i<word.length();i++){
                //i= char index
                char startWord=word[i];
                
                for(char j='a';j<='z';j++){

                    word[i]=j;

                    if(mp.count(word)){

                        if(word==endWord){
                            return steps+1;
                        }

                        mp.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=startWord;
            }
        }
        return 0;
    }
};