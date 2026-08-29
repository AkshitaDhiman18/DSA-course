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

 /*temp1 → node before a
bptr  → node b
next  → node after b*/
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* dummy= new ListNode(0);
        dummy->next= list1;

        ListNode* temp1= dummy;
        ListNode* temp2= list2;

        int i=0;
        while(i<a){
            temp1= temp1->next;
            i++;
        }
        ListNode* aptr= temp1->next;
        ListNode* bptr= aptr;
        i=a;
        while(i<b){
            bptr= bptr->next;
            i++;
        }

        ListNode* next= bptr->next;
        temp1->next= nullptr;
        bptr->next= nullptr;

        temp1->next= temp2;

        while(temp2->next != nullptr){
            temp2= temp2->next;
        }

        temp2->next= next;

        return dummy->next;
    }
};