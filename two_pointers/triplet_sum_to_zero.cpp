/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.
*/

//O(N^2) Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        int front, rear, sum, tgt;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size(); i++){            
            if ((i>0) && (nums[i] == nums[i-1])){
                continue;
            }            
            tgt = 0 - nums[i];
            
            //sorted array so if tgt < 0 means nums[i] is +ve and all later items are +ve as well
            if (tgt<0) break;
            
            front = i+1; rear = nums.size() -1;            
            while (front < rear){
                sum = nums[front] + nums[rear];
                
                if (sum == tgt){
                    //remove the duplicates
                    while (front+1 < rear && nums[front] == nums[front+1]) front++;
                    while (rear-1 > front && nums[rear] == nums[rear-1]) rear--;
                    
                    vector<int> tmp = {nums[i], nums[front], nums[rear]};
                    result.push_back(tmp);
                    
                    front++; rear--;
                } else if (sum < tgt){
                    front++;
                } else {
                    rear--;
                }
            }
        }
        return result;
    }
};