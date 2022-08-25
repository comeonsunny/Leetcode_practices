// 707. Design Linked List
/*
    Design your your implementation of the linked list. 
    You can choose to use a singly or doubly linked list.
    A node in a singly linked list should have two attributes: val and next. 
    Val is the value of the current node, and next is a pointer/reference to the next node. 
    If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node 
    in the linked list. Assume all nodes in the linked list are 0-indexed.
    Implement the MyLinkedList class:
    1. MyLinkedList() initializes the MyLinkedList object.
    2. int get(int index) gets the value of the indexth node in the linked list. If the index is invalid, return -1.
    3. void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
    4. void addAtTail(int val) Append a node of value val as the last element of the linked list.
    5. void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals to the length of linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
    6. void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.  
*/
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class MyLinkedList {
private:
    ListNode *dummy;
    int size;
public:
    MyLinkedList() {
        dummy = new ListNode(0);
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode *cur = dummy->next;
        while (index--) cur = cur->next;
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode *newNode = new ListNode(val);
        newNode->next = dummy->next;
        dummy->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode *newNode = new ListNode(val);
        ListNode *cur = dummy->next;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        ListNode *newNode = new ListNode(val);
        ListNode *cur = dummy;
        while (index--) cur = cur->next;
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        ListNode *cur = dummy;
        while (index--) cur = cur->next;
        ListNode *del = cur->next;
        cur->next = del->next;
        delete del;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main()
{
    MyLinkedList obj = MyLinkedList();
    obj.addAtHead(1);
    obj.addAtTail(3);
    obj.addAtIndex(1,2);   // linked list becomes 1->2->3
    cout << "get(1) = " << obj.get(1) << endl; // returns 2
    obj.deleteAtIndex(1);  // now the linked list is 1->3
    cout << "get(1) = " << obj.get(1) << endl; // returns 3
    return 0;
}