// 203. remove linked list element
/*
    Given the head of a linked list and an integer val, remove all the nodes of the linked list that 
    has Node.val == val, and return the new head of the linked list. 
*/
#include <iostream>
#include <vector>
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
    ListNode* removeElements(ListNode* head, int val) {
        // use the recursive way to solve this problem
        // if (head == nullptr) return nullptr;
        // head->next = removeElements(head->next, val);
        // return head->val == val ? head->next : head;
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *pre_node = dummy;
        ListNode *cur_node;
        while (pre_node->next) {
            if (pre_node->next->val == val) {
                cur_node = pre_node->next;
                pre_node->next = cur_node->next;
                delete cur_node;
            } else {
                pre_node = pre_node->next;
            }
        }
        return dummy->next;
    }
};
// generate a linklist inters of an array nums
ListNode* generateLinkList(vector<int>& nums) {
    ListNode *head = new ListNode(nums[0]);
    ListNode *node = head;
    for (int i = 1; i < nums.size(); i++) {
        node->next = new ListNode(nums[i]);
        node = node->next;
    }
    return head;
}
int main()
{
    vector<int> nums = {1, 2, 6, 3, 4, 5, 6};
    ListNode *head = generateLinkList(nums);
    ListNode *cur_node = head;
    cout << "original linklist: ";
    while (cur_node) {
        cout << cur_node->val << " ";
        cur_node = cur_node->next;
    }
    cout << endl;
    Solution s;
    ListNode *new_head = s.removeElements(head, 6);
    cout << "new linklist: ";
    while (new_head) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;
    return 0;
}