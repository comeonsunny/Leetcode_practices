// 19 remove nth node from end of list
/*
    Given the head of a linked list, remove the n^th node from the end of the list and return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        ListNode *q = dummy;
        while (n--) {
            p = p->next;
        }
        while (p->next) {
            p = p->next;
            q = q->next;
        }
        ListNode *del = q->next;
        q->next = q->next->next;
        delete del;
        return dummy->next;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode *res = s.removeNthFromEnd(head, 2);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}