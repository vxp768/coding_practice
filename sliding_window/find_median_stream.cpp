/*
 *  1. Use two priority queues
 *  2. Use multiset...has property of balanced BST
 */ 

//Using multiset
class MedianFinder {
    multiset<int> nums;
    multiset<int>::iterator lo_median, hi_median;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //record size before inserting
        int size = nums.size();
        
        nums.insert(num);
        if(size==0){
            lo_median = hi_median = nums.begin();
            return;
        }
        if(size & 1) {
            //odd before inserting new elem...to manipulate iterator...need to add first
            if(num < *lo_median) {
                lo_median--;
            } else {
                hi_median++; //in multiset insert happens at end if equal
            }
        } else {
            //even before
            if(num > *lo_median && num < *hi_median) {
                lo_median++; hi_median--; //both point to same num
            } else if (num >= *hi_median){
                lo_median++;
            } else { //for cases num is less than or equal to lo_median
                // new num would have been added between lo and hi if num was equal to lo_med
                hi_median--;
                lo_median = hi_median;
            }
        }
    }
    
    double findMedian() {
        // multiply by 1/2 to cover both odd and even cases
        return ((double)*lo_median + *hi_median) * 0.5;
        
    }
};



// Using priority queues
class MedianFinder {
    priority_queue<int> max_heap;                 //to store left side of array
    priority_queue<int, vector<int>, greater<int>> min_heap; //to store right side of array
public:
    /** initialize your data structure here. */
    MedianFinder() {   
    }
    void addNum(int num) {
        //check the size of both heaps
        int max_size = max_heap.size();
        int min_size = min_heap.size();
        
        if(max_size == 0){
            max_heap.push(num);
            return;
        }
        if(max_size==min_size) {
            if(num < max_heap.top()){
                max_heap.push(num);
            } else if(num > min_heap.top()) {
                min_heap.push(num);    
            } else {
                //num in between top of both heaps
                max_heap.push(num);
            }
        } else {
            if(max_size > min_size){ //max size is bigger
               if(num < max_heap.top()){
                   //extract top from max heap and push to min heap
                   int max_num = max_heap.top();
                   max_heap.pop();
                   min_heap.push(max_num);
                   //push new num to max heap
                   max_heap.push(num);
               } else {
                   min_heap.push(num);
               }
            } else { //min size is bigger
                if(num > min_heap.top()){
                    //extract top from min and push it to max_heap
                    int min_num = min_heap.top();
                    min_heap.pop();
                    max_heap.push(min_num);
                    min_heap.push(num);
                } else {
                    max_heap.push(num);
                }
            }
        }
    }
    double findMedian() {
        //check the size of both heaps
        int max_size = max_heap.size();
        int min_size = min_heap.size();
        if(max_size==min_size) {
            int med1 = max_heap.top();
            int med2 = min_heap.top();
            return ((double)med1+med2)/2;
        } else {
            if(max_size > min_size){
                return max_heap.top();
            } else {
                return min_heap.top();
            }
        }
    }
};