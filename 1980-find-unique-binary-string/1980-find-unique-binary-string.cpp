class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        unordered_map<int,int> num;

        for(int i=0;i<nums.size();i++){
            string number=nums[i];

            int power=1;
            int binary=0;
            for(int j=number.length()-1;j>=0;j--){
                if(number[j]=='1'){
                    binary=power+binary;
                }
                power*=2;
            }

            num[binary]=i;
            
        }

        long long range=pow(2,nums.size());

        long long bits=-1;
        for(int i=0;i<range;i++){
            if(num.find(i)==num.end()){
                bits=i;
                break;
            }
        }

        string ans(nums.size(),'0');
        if(bits==0){
            return ans;
        }

        int j=nums.size()-1;
        while(bits>0){
            int rem=bits%2;
            ans[j--]=rem+'0';
            bits/=2;
        }

        return ans;
    }
};