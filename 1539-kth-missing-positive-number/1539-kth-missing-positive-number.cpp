class Solution {


    int linear(vector<int>& arr, int k){

        int i=0;
        while(i<arr.size() && arr[i]<=k){
            k++;
            i++;
        }
        return k;
    }

    int binarySearch(vector<int>& arr, int k){


        int start=0;
        int end=arr.size()-1;

        while(start<=end){

            int mid=start+(end-start)/2;

            if(arr[mid]-(mid+1)<k){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        //range in which the k will be end to start

    //    int missingTillEnd=arr[end]-(end+1);

    //     int ans=arr[end]+k-missingTillEnd;
    //     return ans;
        //but this will not work if missing nums is the starting-1 number so we do further


       //or on further solving ans we get (k+end+1)= k+start
      return k+end+1;
        //return k+start;


        
    }
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        //return linear(arr,k);
        

        return binarySearch(arr,k);
    }
};