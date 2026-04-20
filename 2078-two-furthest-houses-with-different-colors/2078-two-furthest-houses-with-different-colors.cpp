class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        //two pass
        // from leftmost to farthest right
    int ans=0;
      
        int j=colors.size()-1;
        while(j>0 && colors[j]==colors[0]){
            j--;
        }

        ans=max(ans, abs(j));

        int i=0;
        while(i<colors.size() && colors[i]==colors[colors.size()-1]){
            i++;
        }
        
        ans=max(ans, (int)colors.size()-i-1);
        
        return ans;

    }
};