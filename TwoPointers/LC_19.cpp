/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //two pointers approach
        ListNode* first = head;
        ListNode* second = head;
        // Move first pointer n steps ahead, we do this to maintain the gap of n nodes between first and second pointers which will help us find the nth node from the end
        for (int i = 0; i < n; i++) {
            first = first->next;
        }
        // If first pointer is null, it means we need to remove the head
        if (!first) {
            return head->next;
        }
        // Move both pointers until first pointer reaches the end
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        // Now second pointer is at the node before the one we want to remove
        second->next = second->next->next; // Remove the nth node from the end
        return head; // Return the modified list
    }
};

/*

Given the head of a linked list, remove the nth node from the end of the list and return its head.

*/