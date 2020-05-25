/*
 * Given an array nums, there is a sliding window of size k which is moving 
 * from the very left of the array to the very right. You can only see the k numbers in the window. 
 * Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

 */
 // USING Double ended queue deque
 // largest element in window always appear in front of deque
 class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> result;
        for(int i=0; i<k; i++){
            while(!deq.empty() && nums[i] >= nums[deq.back()]) {
                deq.pop_back();
            }
            deq.push_back(i);
        }
        
        for(int i=k; i<nums.size(); i++){
            result.push_back(nums[deq.front()]);
            while(!deq.empty() && nums[i] >= nums[deq.back()]) {
                deq.pop_back();
            }
            while(!deq.empty() && deq.front() <= i-k){
                deq.pop_front();
            }
            deq.push_back(i);
        }
        result.push_back(nums[deq.front()]);
        return result;
    }
};



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> left(n,0), right(n,0), result;
        if(n * k == 0)
            return result;
        if (k==1)
            return nums;
            
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            //populate left array
            if(i%k==0) { 
                left[i] = nums[i];
            } else {
                left[i] = max(left[i-1], nums[i]);
            }
            //populate right array
            int j = (n-1) - i;
            if((j+1)%k == 0) {
                //blk end
                right[j] = nums[j];
            } else {
                right[j] = max(right[j+1], nums[j]);
            }
        }
        for (int i=0; i<= nums.size()-k; i++){
            result.push_back(max(right[i], left[i+k-1]));
        }
        return result;
    }
};