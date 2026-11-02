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
 //List ko x ke basis par do groups mein arrange karo — pehle < x, phir >= x, while dono groups ke andar original order same rehna chahiye.
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        if(head == nullptr) return nullptr;

        //new pointers creations
        ListNode* dummy= new ListNode(0);
        ListNode* dummy1= new ListNode(0);
        ListNode* prev= dummy;
        ListNode* prev1= dummy1;

        ListNode* temp= head;

        while(temp != nullptr){
            int value= temp->val;
            ListNode* forward= temp->next;

            if(value < x){
                prev->next= temp;
                prev= temp;
            }else{
                prev1->next= temp;
                prev1= temp;
            }

             temp->next= nullptr;
             temp= forward;
        }

        prev->next= dummy1->next;

        return dummy->next;
    }
};