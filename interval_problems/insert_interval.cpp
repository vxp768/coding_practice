/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i=0;
        for(i=0; i<intervals.size(); i++){
            if(intervals[i][1] < newInterval[0]){
                result.push_back(intervals[i]);
            } else {
                break;
            }
        }
        result.push_back(newInterval);
        if(i<intervals.size()){
            if(intervals[i][0] > newInterval[1]){
                //disjoint sets as above for loop stops at intervals[i][1] > newint[0]
                result.push_back(intervals[i]);
            } else {
                if(intervals[i][0] < newInterval[0]){
                    result.back()[0] = intervals[i][0];
                }
                if(intervals[i][1] > newInterval[1]){
                    result.back()[1] = intervals[i][1];
                }
            }
        }
        for(int k=i+1; k<intervals.size(); k++){
            if(intervals[k][0] <= result.back()[1]){
                if(intervals[k][1] > result.back()[1])
                    result.back()[1] = intervals[k][1];
            } else {
                result.push_back(intervals[k]);
            }
        }
        
        return result;
    }
};