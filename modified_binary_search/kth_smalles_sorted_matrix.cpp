/*Given a n x n matrix where each of the rows and columns are sorted in ascending order,
 find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 * 
 */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //Use binary search and use number range as search space and not index 
        int start = matrix[0][0];
        int end   = matrix[matrix.size()-1][matrix[0].size()-1];

        while(start < end){
            int middle = start + (end-start)/2;
            //find number of elems in matrix less than middle
            int count = 0;
            int col=matrix.size()-1;
            for(int i=0; i<matrix.size(); i++) {
                while(col >= 0 && matrix[i][col]>middle){
                    col--;
                }
                count += col+1; //count of elems smaller than middle
            }
            if(count < k) {
                start = middle+1;
            } else {
                end = middle;
            }
        }
        return start;    
    }
};

//Using Heap
class Solution {
    struct compare {
        bool operator()(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b){
           return a.first > b.first;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> min_heap;
        int ans;
        for(int i=0; i<matrix.size(); i++){
            min_heap.push(make_pair(matrix[i][0], make_pair(i, 0)));
        }
        while(k){
            ans = min_heap.top().first;
            int row = min_heap.top().second.first;
            int col = min_heap.top().second.second;
            min_heap.pop();
            if(col < matrix[0].size()-1){
                min_heap.push(make_pair(matrix[row][col+1], make_pair(row, col+1)));
            }
            k--;
        }
        return ans;
    }
};