/*
 Find dupliocate in array. only one duplicate exists but it can occur multiple times

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow!=fast);
        slow=nums[0];
        //find start of cycle
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};

//Using set
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> S;
        for(int i=0; i<nums.size(); i++){
            if(S.find(nums[i]) != S.end()){
                return nums[i];
            }
            S.insert(nums[i]);
        }
        return -1;
    }
};