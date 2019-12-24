class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
         //bitset starts its indexing backward that is for 
         //10110, 0 are at 0th and 3rd indices whereas 1 are at 1st 2nd and 4th indices.
         bitset<5001> bits(1);      //5000......4 3 2 1 0
         int sum = accumulate(nums.begin(), nums.end(), 0);
    
        //left shift for all nums
        //end result in bits will have bit num==sum set and also
        //if sum/2 is possible that bit will be set
        for (auto n : nums) 
            bits |= bits << n;
    
        //in case sum is odd return false
        return !(sum & 1) && bits[sum >> 1];
    }
};