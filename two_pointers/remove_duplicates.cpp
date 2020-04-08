//Remove duplicates from array
//return length of arr with no dups
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        if(nums.size()==0)
            return 0;
        for(int j=0; j<nums.size(); j++) {
            if(nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
