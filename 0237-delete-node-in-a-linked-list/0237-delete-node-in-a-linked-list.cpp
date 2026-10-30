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
        ListNode* newnode= node->next;
        node->val= newnode->val;
        node->next= newnode->next;
        newnode->next= nullptr;
        delete newnode; 
    }
};