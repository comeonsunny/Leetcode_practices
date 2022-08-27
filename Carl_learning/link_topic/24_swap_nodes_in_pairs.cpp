// 24 swap nodes in pairs
/*
    Given a linked list, swap every two adjacent nodes and return its head.
    You must solve the problem without modifying the values in the list's nodes (i.e., only nodes 
    themselves may be changed.)
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        swapRecursive(dummy);
        return dummy->next;
    }
    void swapRecursive(ListNode* head) {
        if (head->next == nullptr || head->next->next == nullptr) return;
        ListNode *next_node = head->next;
        ListNode *next_next_node = next_node->next;
        head->next = next_next_node;
        next_node->next = next_next_node->next;
        next_next_node->next = next_node;
        swapRecursive(next_node);
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
    ListNode *new_head = s.swapPairs(head);
    while (new_head != nullptr) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;
    return 0;
}