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
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {

    }
    void push(int x) {
        q1.push(x);
    }
    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return res;
    }
    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        } 
        int res = q1.front();
        q2.push(res);
        q1.pop();
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return res;
    }
    bool empty() {
        return q1.empty();
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