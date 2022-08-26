// Linked List Cycle
/*
    Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following
    the next pointer.
    Internally, pos is used to denote the index of the node that  tail's next pointer is connected to(0-indexed). It is -1 if 
    there is no cycle.
    Note that pos is not passed as a parameter.
    Do not modify the linked list.
*/
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode *meet = fast;
                ListNode *cur = head;
                while (cur != meet) {
                    cur = cur->next;
                    meet = meet->next;
                }
                return cur;
            }
        }
        return nullptr;
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
    ListNode *res = s.detectCycle(head);
    cout << "res: " << res->val << endl;
    return 0;
}