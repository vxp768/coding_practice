/*
*  Split given array in subarrays with consecutive numbers
*
*/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count, end;
        //end keeps track of subseq ending in num
        for(auto num: nums)
            count[num]++;
        
        for(auto num: nums){
            count[num]--;
            if(end[num-1]>0){
                end[num-1]--;
                end[num]++;
            } else if (count[num+1]>0 && count[num+2]>0){
                count[num+1]--;
                count[num+2]--;
                end[num]++;
            } else {
                return false;
            }
        }
        return true;
    }
};
// Using priority queue to keep track of sub-arr lengths
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int, int> count;
        //keep track of sub-seq ending with num...pq to store all the sub-seq
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> sub_seq_pq;
        int less_than_3 = 0;
        for(int i=1; i<nums.size(); i++) {
            count[nums[i]]++;
        }
        for(auto num: nums) {
            if(!sub_seq_pq[num-1].empty()) { //get the sub-seq ending with prev num (num-1)
                int a = sub_seq_pq[num-1].top();
                sub_seq_pq[num-1].pop();
                sub_seq_pq[num].push(++a);
                if (a==3) {
                    less_than_3--;
                }
            } else {
                //start a new sub seq
                sub_seq_pq[num].push(1);
                less_than_3++;
            }
        }
        return less_than_3 == 0;
    }
};
/*
*  Split given array in subarrays of size=k with consecutive numbers 
*
*/
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> count; //count will store nums in sorted manner
        for(auto num: nums){
            count[num]++;
        }
        for(auto it=count.begin(); it!=count.end(); it++) {
            int num = it->first;
            if(it->second){
                int freq = it->second;
                for(int i=1; i<k; i++){
                    if(count[num+i] >= freq){
                        count[num+i] -= freq;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

bool isPossibleDivide(vector<int>& nums, int k) {
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp; //min heap
    int less_than_k=0;
    sort(nums.begin(), nums.end());
    for(auto num: nums) {
        if(!mp[num-1].empty()){
            int seq_len = mp[num-1].top();
            mp[num-1].pop();
            seq_len++;
            if(seq_len<k){
                mp[num].push(seq_len);
            } else if (seq_len==k){
                less_than_k--;
            }
        } else {
            mp[num].push(1);
            less_than_k++;
        }
    }
    return less_than_k==0;
}