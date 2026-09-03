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

    ListNode* swapNodes(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr) return head;
        

        int i=1;
        ListNode* dummy= new ListNode(0);
        dummy->next= head;
        ListNode* first= dummy->next;

        //first node
        while(i<k){
            first= first->next;
            i++;
        }

        //second node;
        ListNode* slow= head;
        ListNode* fast= head;

        int a=1;
        while(a<=k){
            fast= fast->next;
            a++;
        }
        while(fast != nullptr){
            slow= slow->next;
            fast= fast->next;
        }

        //slow represents second node

        int temp= slow->val;
        slow->val= first->val;
        first->val= temp;

        return dummy->next;
    }
};