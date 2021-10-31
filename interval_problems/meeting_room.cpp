/*
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi],
return the minimum number of conference rooms required.

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
       map<int, int> event; //init to zero....will sort the times...ordered map
        
      //store all the timings...start and finish in the map...it will get sorted
      //then consider each entry as event of allocation room and freeing up room
       for(auto it=intervals.begin(); it!= intervals.end(); it++){
           vector<int> meeting = *it;
           event[meeting[0]]++; //event for allocating room
           event[meeting[1]]--; //event for freeing room
       }
        //loop over all the times...events of allocating and freeing
        int cnt=0;
        int maxcnt=0;
        //loop over sorted timings
        for(auto it=event.begin(); it!=event.end(); it++){
            cnt += it->second; // allocate or free
            if(cnt>maxcnt)
                maxcnt = cnt;
        }
        return maxcnt;
    }
};