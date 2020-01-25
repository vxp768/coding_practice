//Method 1: Using 2 stack
class MyQueue {
        stack<int> queue_push;
        stack<int> queue_pop;
public:
    MyQueue() {
    }
    void push(int x) {
        queue_push.push(x);                 //Push is O(1)
    }
    void helper(){
        if(queue_pop.empty()){
            while( !queue_push.empty() ){
                int x = queue_push.top();
                queue_push.pop();
                queue_pop.push(x);
            }
        }
    }
    int pop() {
        int x;          
        helper();                           //Both pop and peek call helper and hence take more time
        x = queue_pop.top();
        queue_pop.pop();
        return x;
    }
    int peek() {
        helper();
        int x = queue_pop.top();
        return x;
    }
    bool empty() {
        return queue_push.empty() && queue_pop.empty();
    }
};

//Method 2: using one stack
class MyQueue {
    stack<int> _stack;
    void reversePush(int x) {
        if(_stack.empty()) {
            _stack.push(x);
            return;
        }
        int k = _stack.top();
        _stack.pop();
        reversePush(x);
        _stack.push(k);
    }
public:
    MyQueue() {
    }
    void push(int x) {
        reversePush(x);         //only push is expensive...pop and peek are O(1)
    }
    int pop() {
        int t = _stack.top();
        _stack.pop();
        return t;
    }
    int peek() {
        return _stack.top();
    }
    bool empty() {
        return _stack.empty();
    }
};