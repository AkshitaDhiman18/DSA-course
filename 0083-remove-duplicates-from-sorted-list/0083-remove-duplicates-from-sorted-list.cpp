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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp= head;
        while(temp != nullptr && temp->next != nullptr){
            ListNode* curr= temp->next;
            int first= temp->val;
            int second= curr->val;

            if(first == second){
                ListNode* forward= curr->next;
                curr->next= nullptr;
                temp->next= forward;
                delete curr;
            }else{
                temp=temp->next;
            }
        }
        return head;  
    }
};