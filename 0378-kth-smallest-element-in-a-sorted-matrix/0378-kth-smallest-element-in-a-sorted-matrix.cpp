class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int> maxHeap;

        int size=matrix.size();

        bool full=false;

        int startRow=-1;
        int startCol=-1;

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){

                if(maxHeap.size()==k){
                        if(matrix[i][j]<maxHeap.top()){
                            maxHeap.pop();
                            maxHeap.push(matrix[i][j]);
                        }
                }
                else{
                    maxHeap.push(matrix[i][j]);
                }
            }
        }

        return maxHeap.top();

        




    }
};