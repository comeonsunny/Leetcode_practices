// 141 linked list cycle
/*
    Given head, the head of a linked list, determine if the linked list has a cycle in it. 
    There is a cycle in a linked list if there is some node in the list that can be reached again
    by continuously following the next pointer.
    Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
    Note that pos is not passed as a parameter.
    Return true if there is a cycle in the linked list. Otherwise, return false.
*/
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *fast_ = head;
        ListNode *slow_ = head;
        while (fast_->next && fast_->next->next) {
            fast_ = fast_->next->next;
            slow_ = slow_->next;
            if (fast_ == slow_) return true;
        }
        return false;
    }
};
int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    Solution s;
    s.hasCycle(head) ? cout << "The linked list has a cycle" : cout << "The linked list has no cycle";
    return 0;
}