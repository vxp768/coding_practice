//Method 1: using 2 queues
class MyStack {
    queue<int> Q1;
    queue<int> Q2;
    queue<int> *cur;
    queue<int> *next;
public:
    /** Initialize your data structure here. */
    MyStack() {
        cur = &Q1;
        next = &Q2;
    }
    void push(int x) {
        (*cur).push(x);
    }
    int pop() {
        int result;
        while((int)(*cur).size() > 1) {
            int a = (*cur).front();
            (*cur).pop();
            (*next).push(a);
        }
        result = (*cur).front();
        (*cur).pop();
        swap(cur , next);
        return result;
    }
    int top() {
        int result, a;
        while((int)(*cur).size() > 0) {
            a = (*cur).front();
            (*cur).pop();
            (*next).push(a);
        }
        result = a;
        swap(cur , next);
        return result;
    }
    bool empty() {
        if((*cur).size()==0 && (*next).size()==0)
            return true;
        else
            return false;
    }
};


//Mehtod 2: using 1 queue
class MyStack {
    queue<int> Q1;
public:
    MyStack() {
    }
    void push(int x) {
        Q1.push(x);
        int size = Q1.size();
        while(size > 1){
            Q1.push(Q1.front());
            Q1.pop();
            size--;
        }
    }
    int pop() {
        int result = Q1.front();
        Q1.pop();
        return result;
    }
    int top() {
        return Q1.front();
    }
    bool empty() {
        if(Q1.size()==0)
            return true;
        else
            return false;
    }
};