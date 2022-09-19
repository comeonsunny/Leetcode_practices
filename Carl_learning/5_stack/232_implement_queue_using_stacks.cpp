// 232 Implement Queue using Stacks
/*
    Implement a first in first out (FIFO) queue using only two stacks.
    The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
    Implement the MyQueue class:
      void push(int x) Pushes element x to the back of the queue.
      int pop() Removes the element from the front of the queue and returns it.
      int peek() Returns the element at the front of the queue.
      boolean empty() Returns true if the queue is empty, false otherwise.
    Notes:
        You must use only standard operations of a stack, which means only push to top, peek/pop from top, 
        size, and is empty operations are valid. 
        Depending on your language, the stack may not be supported natively. 
        You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
*/
#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
private:
    stack<int> s_in;
    stack<int> s_out;
public:
    MyQueue() {
    }
    
    void push(int x) {
      if (s_out.empty()) {
        s_in.push(x);
      } else {
        while (!s_out.empty()) {
          s_in.push(s_out.top());
          s_out.pop();
        }
        s_in.push(x);
      }
    }
    
    int pop() {
      int res;
      if (s_in.empty()) {
        res = s_out.top();
        s_out.pop();
      } else {
        while (!s_in.empty()) {
          s_out.push(s_in.top());
          s_in.pop();
        }
        res = s_out.top();
        s_out.pop();
      }
      return res;
    }
    
    int peek() {
      int res;
      if (s_in.empty()) {
        res = s_out.top();
      } else {
        while (!s_in.empty()) {
          s_out.push(s_in.top());
          s_in.pop();
        }
        res = s_out.top();
      }
      return res;
    }
    
    bool empty() {
      return s_in.empty() && s_out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 int main() {
   MyQueue* obj = new MyQueue();
   obj->push(1);
   obj->push(2);
   obj->push(3);
   cout << obj->pop() << endl;
   cout << obj->peek() << endl;
   cout << obj->empty() << endl;
   return 0;
 }