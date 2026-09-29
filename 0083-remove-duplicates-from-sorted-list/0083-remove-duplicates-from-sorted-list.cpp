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

       if(head== nullptr) return head;
       ListNode* dummy= new ListNode(0);
       dummy->next= head;

       ListNode* prev= dummy;
       ListNode* temp= head;

       while(temp->next != nullptr){
        ListNode* forward= temp->next;

        if(temp->val == forward->val){
            ListNode* del= temp;
            del->next= nullptr;

            prev->next= forward;
            delete del;
            temp= forward;
        }else{
            prev= prev->next;
            temp= temp->next;
        }
       }

       return dummy->next;
    }
};