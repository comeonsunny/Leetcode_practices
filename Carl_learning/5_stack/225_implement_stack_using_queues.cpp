// 225 implement stack using queues
/*
    Implement a last-in-first-out (LIFO) stack using only two queues.
    The implemented stack should support all the functions of a normal queue (push, top, pop, and empty).
    Implement the MyStack class:
    void push(int x) Pushes element x to the top of the stack.
    int pop() Removes the element on the top of the stack and returns it.
    int top() Returns the element on the top of the stack.
    boolean empty() Returns true if the stack is empty, false otherwise.
    Notes:
    You must use only standard operations of a queue, which means only push to back, peek/pop
    from front, size, and is empty operations are valid.
    Depending on your language, the queue may not be supported natively.
    You may simulate a queue using a list or deque (double-ended queue), as long as you use only a queue's standard operations.
*/
#include <iostream>
#include <queue>
using namespace std;
class MyStack {
private:
    queue<int> q;
public:
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size();
        int res;
        if (n == 1) {
            res = q.front();
            q.pop();
            return res;
        }
        for (int i = 0; i < n - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        int n = q.size();
        int res;
        if (n == 1) {
            res = q.front();
            return res;
        }
        for (int i = 0; i < n - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        res = q.front();
        q.pop();
        q.push(res);
        return res;
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() 
{
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    return 0;
}