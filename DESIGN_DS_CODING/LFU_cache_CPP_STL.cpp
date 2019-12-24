/* LFU cache
 * If frequency is same then use LRU among the keys
 */
class LFUCache {
    unordered_map<int, int> key_value;    //Store key to value mapping
    unordered_map<int, int> key_freq;       //Store key to frequency mapping
    map<int, deque<int>> freq_key;          //Store freq to list of keys mapping....always add in front of Queue for LRU
    int cache_size;
public:
    LFUCache(int capacity) {
       cache_size = capacity; 
    }
    int get(int key) {
        if(key_value.find(key)!=key_value.end()){
            update_freq(key);    
            return key_value[key];
        } else {
            return -1;
        }
    }
    void update_freq(int key){
        auto it = key_freq.find(key);
        if(it == key_freq.end()){
            //key seen first time
            key_freq[key]=1;
            freq_key[1].push_front(key);
        } else {
            //update freq--deque mapping
            int freq = it->second;
            deque<int>& tmp = freq_key[freq];
            for(auto it1 =tmp.begin(); it1!=tmp.end(); it1++){
                if(*it1 == key){
                    tmp.erase(it1);
                    break;
                }
            }
            if(tmp.size()==0){
                freq_key.erase(freq);
            }
            //update freq
            freq++;
            freq_key[freq].push_front(key);
            key_freq[key]=freq;
        }
    }
    void put(int key, int value) {
        if(cache_size==0)
            return;
       if(key_value.find(key)==key_value.end() && key_value.size()==cache_size){
           //evict
           auto it = freq_key.begin();
           int freq_remove = it->first;
           int key_remove = (it->second).back();
           key_value.erase(key_remove);
           key_freq.erase(key_remove);
           (it->second).pop_back();
           if(it->second.size()==0) {
               freq_key.erase(freq_remove);
           }
       }
       key_value[key] = value;
       update_freq(key);    
    }
};