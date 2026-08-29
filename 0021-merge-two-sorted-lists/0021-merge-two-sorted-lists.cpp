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
    
    int get_len(ListNode* head){
        int len=0;
        while(head != nullptr){
            len++;
            head= head->next;
        }
        return len;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* temp1= list1;
        ListNode* temp2= list2;

        if(temp1 == nullptr && temp2 == nullptr) return nullptr;

        /*if(temp1 == nullptr) return temp2;
        if(temp2 == nullptr) return temp1;*/

        ListNode* dummy= new ListNode(0);
        dummy->next= list1;

        //ListNode* point= dummy;
        ListNode* prev= dummy;

        while(temp1 != nullptr && temp2 != nullptr){
            int value1= temp1->val;
            int value2= temp2->val;

            if(value1 <= value2){
                prev= temp1;
                temp1= temp1->next;

            }else if(value2 < value1){
                //ListNode* forward1= temp1->next;
                ListNode* forward2= temp2->next;
                temp2->next= nullptr;
                prev->next= temp2;
                temp2->next= temp1;
                prev= temp2;

                temp2= forward2;
            }
        }

        if(temp1 == nullptr){
            prev->next= temp2;
        }

        return dummy->next;   
    }
};