//ONE WAY to find media in a stream is to maintain sel balancing tree (AVL) and 
//tree root and/or one of it's children will give "median"
//Other way to is to use two heaps


/*
 * The size of two heaps should not differ by more than 1
 * 
 */
class MedianFinder {
    priority_queue<int> max_heap;                            //to store left side of array
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

//OPTIMIZED use of heaps
class MedianFinder {
    priority_queue<int> max_heap;                 //to store left side of array
    priority_queue<int, vector<int>, greater<int>> min_heap; //to store right side of array
public:
    /** initialize your data structure here. */
    MedianFinder() {   
    }
    void addNum(int num) {
        max_heap.push(num);     //always add to max heap
        
        min_heap.push(max_heap.top()); //move the top of max to min heap....e.g add 1,2,3 in seq
        max_heap.pop();
        
        if(max_heap.size() < min_heap.size()) { //take care of size of two heaps...max_heap can only be 1 bigger than min_heap
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    double findMedian() {
        if(max_heap.size() == min_heap.size()) {
            int med1 = max_heap.top();
            int med2 = min_heap.top();
            return ((double)med1+med2)/2;
        } else {
            return max_heap.top();
        }
    }
};

//Using multiset
class MedianFinder {
    multiset<int> multi_set;
    multiset<int>::iterator medium_iter;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int size = multi_set.size();
        if(!size) {
            multi_set.insert(num);
            medium_iter = multi_set.begin();
            return;
        }
        multi_set.insert(num);
        if(size & 1){
            //odd
            if(num < *medium_iter)
                medium_iter--;
            //else medium iter becomes iter for first medium in even array
        } else {
            //even
            if(num >= *medium_iter)
                medium_iter++;
            //else medium_iter becomes iter for mid elem in odd array
        }
    }
    
    double findMedian() {
        if(multi_set.size()%2==0){
            //even
            return ((double)(*medium_iter)+ *next(medium_iter))/2;
        } else {
            return (double)(*medium_iter);
        }
    }
};