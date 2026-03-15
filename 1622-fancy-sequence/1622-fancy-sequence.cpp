class Fancy {
    vector<long long> nums;
public:
    Fancy() {
        vector<long long> nums(nums.size());
    }
    
    void append(int val) {
        nums.push_back(val);
    }
    
    void addAll(int inc) {

        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]+inc;
        }
        
    }
    
    void multAll(int m) {
        for(int i=0;i<nums.size();i++){
            nums[i]=((long long )nums[i]*m)%1000000007;
        }
    }
    
    int getIndex(int idx) {
        if(idx>=nums.size()){
            return -1;
        }

        return nums[idx]%1000000007;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */