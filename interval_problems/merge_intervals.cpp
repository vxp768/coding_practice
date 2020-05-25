/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size() == 0){
            return result;
        }
        sort(intervals.begin(), intervals.end());
        result.push_back({intervals[0][0], intervals[0][1]});
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= result.back()[1]){
                //merge
                if(intervals[i][1] > result.back()[1])
                   result.back()[1] = intervals[i][1]; //change the finish time
            } else {
                result.push_back({intervals[i][0], intervals[i][1]});
            }
        }     
        return result;
    }   
};