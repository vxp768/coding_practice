/* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
   find the area of largest rectangle in the histogram.
   
*/
//Using Stack O(N)...keep track of minimum height on left and on right
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> S;
        int max_area=0;
        if(heights.size()==0)
            return max_area;
        for(int i=0; i<heights.size(); i++){
            if(S.empty() || heights[i]>=heights[S.top()]){
               S.push(i);
            } else if(heights[i]<heights[S.top()]) {
                //pop all elems higher than i 
                while(!S.empty()&&heights[i] < heights[S.top()]) {
                    int idx = S.top();
                    S.pop();
                    max_area = max(max_area, heights[idx]*(S.empty()?i:i-S.top()-1));
                }
                S.push(i);
            }
        }
        int last_idx  = heights.size();
        while(!S.empty()) {
            int idx = S.top();
            S.pop();
            max_area = max(max_area, heights[idx]*(S.empty()?last_idx : last_idx-S.top()-1));
        }
        return max_area;
    }
};


//BRUTE FORCE: start at each rectangle...loop thru for rest of rectangles and keep track of min heights
//             multiply min height with number of rectangles and update max_area
//O(N^2)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area=INT_MIN;
        int area=0;
        for(int i=0; i<heights.size(); i++) {
            int min_height=INT_MAX;
            for(int j=i; j<heights.size(); j++) {
                min_height = min(min_height, heights[j]);
                area = (j-i+1)*min_height;
                max_area = max(area, max_area);
            }
        }
        return max_area==INT_MIN?0:max_area;
    }
};

