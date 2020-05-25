/*
 * Top k frequent elements
 *
 */
 
 // USE Priority queue
 class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> n_map;
        for(auto num: nums){
            n_map[num]++;
        }
        vector<int> result;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it=n_map.begin(); it!=n_map.end(); it++) {
            //MIN HEAP
            pq.push(make_pair(it->second, it->first)); //freq,key
            //keep popping mins as we need k largest
            if(pq.size() > k) {
                pq.pop();
            }
        }
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

// Use bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> n_map;
        for(auto i : nums) {
            n_map[i]++;
        }
        //BUCKET SORT
        vector<vector<int>> buckets(nums.size() + 1);  //max freq of a num can be size of nums array
        for(auto & i : n_map) {
            buckets[i.second].push_back(i.first);       //bucket idx is freq of num
        }
        //reverse from inc to dec
        reverse(buckets.begin(), buckets.end());
        vector<int> result;
        for (auto & bucket : buckets) {
            for (auto i : bucket) {
                result.push_back(i);
                if (result.size() == k) return result;
            }
        }
        return result;
    }
};