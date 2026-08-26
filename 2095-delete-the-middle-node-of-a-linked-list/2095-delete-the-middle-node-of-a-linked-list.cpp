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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr) return head;

        if(head->next == nullptr){
            ListNode* temp= head;
            head= temp->next;
        }else{

            ListNode* slow=head;
            ListNode* fast= head;

            while(fast != nullptr && fast->next != nullptr){
                slow=slow->next;
                fast= fast->next->next;
            }

            ListNode* prev= head;
            while(prev->next != slow){
                prev= prev->next;
            }

            ListNode* forward= slow->next;
            slow->next= nullptr;

            prev->next= forward;
            }
            
        return head; 
    }
};