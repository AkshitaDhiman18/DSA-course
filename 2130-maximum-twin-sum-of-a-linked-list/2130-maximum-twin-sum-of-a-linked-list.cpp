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
#include <climits>
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast= head;
        //middle nikla
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast= fast->next->next;
            slow= slow->next;
        }

        ListNode* next= slow->next;
        slow->next= nullptr;
        //second half reverse kra
        ListNode* prev= nullptr;

        ListNode* temp= next;
        while(temp != nullptr){
            ListNode* forward= temp->next;
            temp->next= prev;

            prev= temp;
            temp= forward;
        }
        int max_twinsum= INT_MIN;
        while(prev != nullptr){
            int value1= head->val;
            int value2= prev->val;

            max_twinsum= max(max_twinsum, value1 + value2);

            head= head->next;
            prev= prev->next;
        }

        return max_twinsum;
       
    }
};