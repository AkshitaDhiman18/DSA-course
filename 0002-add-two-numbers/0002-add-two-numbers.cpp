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
    int get_length(ListNode* head){
        int len=0;
        while(head != nullptr){
            len++;
            head= head->next;
        }
        return len;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //size same karo
        //addition kro

        int size1= get_length(l1);
        int size2= get_length(l2);
        int diff= abs(size1 - size2);

        if(size1 < size2){
            ListNode* tail= l1;
            while(tail->next != nullptr){
                tail= tail->next;
            }

            int i=0;
            while(i<diff){
                ListNode* temp= new ListNode(0);
                tail->next= temp;
                tail= tail->next;
                i++;
            }
            tail->next= nullptr;
        }else if(size2 < size1){
            ListNode* tail= l2;
            while(tail->next != nullptr){
                tail= tail->next;
            }

            int i=0;
            while(i<diff){
                ListNode* temp= new ListNode(0);
                tail->next= temp;
                tail= tail->next;
                i++;
            }
            tail->next= nullptr;
        }

        int carry=0;
        ListNode* dummy= new ListNode(0);
        dummy->next= l1;
        ListNode* prev= dummy;
        ListNode* pt1= l1;
        ListNode* pt2= l2;

        while(pt1 != nullptr){
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
        if(carry != 0){
            ListNode* new_node= new ListNode(carry);
            prev->next= new_node;
            new_node->next= pt1;
        }

        return dummy->next;

    }
};