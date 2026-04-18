class Solution {

    int rev(int &element){
        
        int num=0;

        while(element>0){
            int last=element%10;
            num=(num*10)+last;
            element/=10;
        }

        return num;
    }
public:
    int mirrorDistance(int n) { 
        int element=n;
        return abs(n-rev(element));
    }
};