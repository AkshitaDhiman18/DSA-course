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
  

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        //addition kro

        int carry=0;
        ListNode* dummy= new ListNode(0);
        dummy->next= l1;
        ListNode* prev= dummy;
        ListNode* pt1= l1;
        ListNode* pt2= l2;

        while(pt1 != nullptr && pt2 != nullptr){
            int a= pt1->val;
            int b= pt2->val;
            int value= a + b + carry;

            int num= value % 10;
            carry= value /10;

            pt1->val= num;
            pt1= pt1->next;
            pt2= pt2->next;
            prev= prev->next;
        }

        if(pt1== nullptr){
            while(pt2 != nullptr){
            int a= pt2->val;
            int value= a + carry;

            int num= value % 10;
            carry= value / 10;

            ListNode* new_node= new ListNode(num);
            prev->next= new_node;
            new_node->next= pt1;

            pt2= pt2->next;
            prev= prev->next;
        }

        if(carry != 0){
            ListNode* new_node= new ListNode(carry);
            prev->next= new_node;
            new_node->next= pt1;
        }
        return dummy->next;
    }
        if(pt2 == nullptr){
            while(pt1 != nullptr){
                int a= pt1->val;
                int value= a + carry;

                int num= value % 10;
                carry= value / 10;

                pt1->val= num;
                pt1=pt1->next;
                prev= prev->next;
            }

            if(carry != 0){
                ListNode* new_node= new ListNode(carry);
                prev->next= new_node;
                new_node->next= pt1;
            }
        }

        return dummy->next;

    }
};