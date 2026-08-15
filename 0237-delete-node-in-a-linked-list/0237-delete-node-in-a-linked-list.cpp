/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //change the value of node because node is not the last node so we have next node due to which we can copy the val
        node->val= node->next->val;
        //pointers setup
        ListNode* curr= node->next;
        ListNode* forward= curr->next;
        curr->next= nullptr;
        node->next=forward;
        delete curr; 
    }
};