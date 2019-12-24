/*
 Given a circular array (the next element of the last element is the first element of the array), 
 print the Next Greater Number for every element. The Next Greater Number of a number x is the 
 first greater number to its traversing-order next in the array, 
 which means you could search circularly to find its next greater number. 
 If it doesn't exist, output -1 for this number.
Input: [1,2,1]
Output: [2,-1,2]   
*/

//O(n^2) solution
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int size = nums.size();
        for(int i=0; i<nums.size(); i++){
            result[i] = -1;
            for(int j=1; j<nums.size(); j++){
                 if(nums[(i+j)%size] > nums[i]){
                     result[i] = nums[(i+j)%size];
                     break;
                 }
            }
        }
        return result;
    }
};

//Using Stack
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.size()==0)
            return vector<int>{};
        vector<int> result(nums.size(), -1);
        stack<int> S;
        S.push(0);
        for(int i=1; i<nums.size(); i++){
            while(!S.empty() && nums[i] > nums[S.top()]){
                result[S.top()] = nums[i];
                S.pop();
            }
            S.push(i);
        }
        for(int i=0; i<nums.size(); i++){
            while(!S.empty() && nums[i] > nums[S.top()]){
                result[S.top()] = nums[i];
                S.pop();
            }
        }
        return result;
    }
};