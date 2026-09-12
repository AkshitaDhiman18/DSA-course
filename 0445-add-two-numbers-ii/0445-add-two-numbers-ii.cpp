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
    ListNode* reverselinkedlist(ListNode* &head){
        ListNode* prev= nullptr;
        ListNode* temp= head;

        while(temp != nullptr){
            ListNode* forward= temp->next;
            temp->next= prev;

            prev= temp;
            temp= forward;
        }
        return prev;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        //reverse and then add using carry

        ListNode* new_head1= reverselinkedlist(l1);
        ListNode* new_head2= reverselinkedlist(l2);
        int carry=0;
        
        ListNode* dummy= new ListNode(0);
        dummy->next= new_head1;
        ListNode* prev= dummy;

        while(new_head1 != nullptr && new_head2 != nullptr){
            int value= new_head1->val + new_head2->val + carry;

            int num= value % 10;
            carry= value / 10;

            new_head1->val= num;
            new_head1= new_head1->next;
            new_head2= new_head2->next;
            prev= prev->next;
        }
    
        while(new_head1 != nullptr){
            int value= new_head1->val + carry;
            int num= value % 10;
            carry= value / 10;

            new_head1->val= num;
            new_head1= new_head1->next;
            prev= prev->next;
        }

        while(new_head2 != nullptr){
            int value= new_head2->val + carry;
            int num= value % 10;
            carry= value / 10;

            ListNode* new_node= new ListNode(num);
            prev->next= new_node;
            new_node->next= new_head1;
            new_head2= new_head2->next;
            prev= prev->next;
        }

        if(carry != 0){
            ListNode* new_node= new ListNode(carry);
            prev->next= new_node;
            new_node->next= new_head1;
        }

        ListNode* HEAD= reverselinkedlist(dummy->next);

        return HEAD; 
    }
};
