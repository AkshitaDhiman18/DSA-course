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

        ListNode* left= dummy;
        ListNode* temp= list2;

        int i=0;
        //temp1 ko a-1 position tak le jaana:
        while(i<a){
            left= left->next;
            i++;
        }
        ListNode* right= left->next;
        
        //bptr ko b position tak le jaana:
        while(i<=b){
            right= right->next;
            i++;
        }
        left->next= temp;

        while(temp->next != nullptr){
            temp= temp->next;
        }

        temp->next= right;

        return dummy->next;
    }
};