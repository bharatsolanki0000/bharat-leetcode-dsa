class MedianFinder {
    priority_queue<int,vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(maxHeap.empty() && minHeap.empty()){
            maxHeap.push(num);
            return ;
        }

        // if(maxHeap.empty() || !minHeap.empty()){
        //     if(num< minHeap.top()){
        //         maxHeap.push(num);
        //     }
        //     else{
        //         int temp=minHeap.top();
        //         minHeap.pop();
        //         maxHeap.push(temp);
        //         minHeap.push(num);
        //     }
        //     return;
        // }

        if(!maxHeap.empty() && minHeap.empty()){
           if(num <maxHeap.top()){
                int temp=maxHeap.top();
                maxHeap.pop();

                maxHeap.push(num);
                minHeap.push(temp);    
           }
           else{
                minHeap.push(num);
           }
           return ;
        }

        if(maxHeap.size()> minHeap.size()){
            int left=maxHeap.top();
            int right=minHeap.top();

            if(num>=left && num<=right){
                minHeap.push(num);
            }
            else if(num<=left){

                int temp=maxHeap.top();
                maxHeap.pop();

                maxHeap.push(num);
                minHeap.push(temp);  
            }
            else if(num>=right){
                minHeap.push(num);
            }
            return ;
        }
        
        if(maxHeap.size()< minHeap.size()){

            int left=maxHeap.top();
            int right=minHeap.top();

            if(num>=left && num<=right){
                maxHeap.push(num);
            }
            else if(num<=left){
                maxHeap.push(num);
               
            }
            else if(num>=right){
                int temp=minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
                minHeap.push(num);
            }
            return;
        }
        

            //both size equal
            int left=maxHeap.top();
            int right=minHeap.top();

            if(num>=left && num<=right){
                maxHeap.push(num);
            }
            else if(num<=left){
                maxHeap.push(num);
            }
            else if(num>=right){
                minHeap.push(num);
            }
        

    }
    
    double findMedian() {

        if(minHeap.empty()){
            return maxHeap.top();
        }

        if(maxHeap.empty()){
            return minHeap.top();
        }


        if((minHeap.size()+maxHeap.size())%2==0){
            //even length
            return (minHeap.top()+maxHeap.top())/2.0;
        }

        if(minHeap.size()>maxHeap.size()){
            return (double)minHeap.top();
        }
        else{
            return (double)maxHeap.top();
        }

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */