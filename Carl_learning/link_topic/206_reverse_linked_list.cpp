// 206 reverse linked list
/*
    Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
    use the two pointers to reverse the linklist
*/
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *pre, *cur, *temp;
        pre = nullptr;
        cur = head;
        while (cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
/* Solution 2 use stack */
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        stack<ListNode*> stk;
        ListNode *cur_node = head;
        while (cur_node) {
            stk.push(cur_node);
            cur_node = cur_node->next;
        }
        ListNode *new_head = stk.top();
        stk.pop();
        cur_node = new_head;
        while (!stk.empty()) {
            cur_node->next = stk.top();
            stk.pop();
            cur_node = cur_node->next;
        }
        cur_node->next = nullptr;
        return new_head;
    }
};
/* Solution 3 use recursive */
class Solution3 {
public:
    ListNode* reverseList (ListNode *head) {
        return reverse (head, nullptr);
    }
    ListNode* reverse(ListNode *cur, ListNode *pre) {
        if (!cur) return pre;
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
};