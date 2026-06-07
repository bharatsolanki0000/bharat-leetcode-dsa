class LRUCache {
    
public:

    int size;

        list<int> dll; //in c++ list behaves as doubly linked list
        unordered_map<int, pair<list<int>::iterator, int>> mp;

        //map to get key = <address,value> pair
    LRUCache(int capacity) {
        size=capacity;
    }

    void mostRecentlyUsed(int key){

        //by inserting it at begin

        auto address=mp[key].first;

        //erase from dll
        dll.erase(address);

        //push to begin
        dll.push_front(key);

        //update address
        mp[key].first=dll.begin();

    }
    
    int get(int key) {
        
        int value=-1;

        if(mp.count(key)){
            value=mp[key].second;
            mostRecentlyUsed(key);
        }
         //make it mostrecentlyused
         
         
        return value;

    }
    
    void put(int key, int value) {
        
        if(mp.count(key)){
            mp[key].second=value;
        }
        else{

            dll.push_front(key);
            mp[key].first=dll.begin();
            mp[key].second=value;
            size--;
        }

        mostRecentlyUsed(key);

        if(size<0){

            int lastKey=dll.back();
            mp.erase(lastKey);

            dll.pop_back();
            size++;
        }

        
    }
};




//     // using vector TLE
//     class LRUCache {
//     int size;
//     vector<pair<int,int>> cache;
// public:
//     LRUCache(int capacity) {
//         size=capacity;    
//     }
    
//     int get(int key) {
        
//         int ans=-1;
//         int index=-1;

//         for(int i=0;i<cache.size();i++){
//             int tempKey=cache[i].first;

//             if(tempKey==key){
//                 ans=cache[i].second;
//                 index=i;
//                 break;
//             }
//         }

//         if(index!=-1){
//             cache.erase(cache.begin()+index);
//             cache.push_back({key,ans});
//         }
//         return ans;
//     }
    
//     void put(int key, int value) {
        
//         for(int i=0;i<cache.size();i++){

//             int tempKey=cache[i].first;

//             if(tempKey==key){
//                 cache.erase(cache.begin()+i);
//                 cache.push_back({key,value});
//                 return ;
//             }
//         }

//         if(cache.size()==size){
//             cache.erase(cache.begin());
//         }
        
//         cache.push_back({key,value});
//     }
// };


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */