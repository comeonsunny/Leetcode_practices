// Sword Point Offer II 0242 Reverse Link List
/*
 Given the head of a singly linked list, reverse the list, and return the reversed linked list's head.
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *pre = dummy, *cur = head, *next_ = nullptr;
        while (cur->next) {
            next_ = cur->next;
            cur->next = next_->next;
            next_->next = pre->next;
            pre->next = next_;
        }
        return dummy->next;
    }
};
int main() 
{
    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    for (int i = 2; i <= 5; i++) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur = head;
    cout << "Before reverse: ";
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    Solution sol;
    ListNode *res = sol.reverseList(head);
    cout << endl << "After reverse: ";
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}