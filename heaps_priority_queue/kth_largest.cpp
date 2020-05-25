/*
Find the kth largest element in an unsorted array.
Example 1:
    Input: [3,2,1,5,6,4] and k = 2
    Output: 5
*/
///       QUICK SELECT
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        random_shuffle(nums.begin(), nums.end());
        return kth_largest(nums, 0, nums.size()-1, nums.size()-k);  // converting k to correct idx
    }
    
    int kth_largest(vector<int> &nums, int l, int r, int k) {
        
        int pos = partition(nums, l, r);
        if(pos == k){
            return nums[pos];
        }
        if(pos < k){
            return kth_largest(nums, pos+1, r, k); //search in right sub array
        }
        return kth_largest(nums, l, pos-1, k); //search left sub array
    }
    
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low;
        for(int j=low; j<=high -1; j++) {
            if(nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }
};


// USING PRIORITY QUEUE...slower than quick select method
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;  //MIN HEAP
        for(int i=0; i<k; i++){
            pq.push(nums[i]);
        }
        for(int i=k; i<nums.size(); i++){
            if(nums[i] > pq.top()){
                pq.push(nums[i]);
                pq.pop();
            }
        }
        return pq.top();
    }
};

//   USING HEAP-SORT
class Solution {
    int heap_size;
public:
    int findKthLargest(vector<int>& nums, int k) {
        // use heapsort
        heap_size=nums.size();
        buildheap(nums);
        for(int i=0; i<k-1; i++){
            swap(nums[0], nums[heap_size-1]);
            heap_size--;
            heapify(nums, 0);
        }
        return nums[0];
    }
    void heapify(vector<int> &nums, int idx){
        int l_c = 2*idx + 1;
        int r_c = 2*idx + 2;
        int max=idx;
        if(l_c<heap_size && nums[l_c] > nums[max]){
                max = l_c;
        }
        if(r_c<heap_size && nums[r_c] > nums[max]){
                max = r_c;
        }
        if(max != idx){
            swap(nums[max], nums[idx]);
            heapify(nums, max);
        }
    }
    void buildheap(vector<int> &nums) {
        int parent = ((nums.size()-1)-1)/2;
        for(int i=parent; i>=0; i--){
            heapify(nums, i);
        }
    }
};