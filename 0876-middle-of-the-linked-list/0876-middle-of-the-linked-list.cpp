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
#include <cmath>
class Solution {
public:
    int getlen(ListNode* head){
        int len=0;
        ListNode* temp= head;
        while(temp != nullptr){
            len++;
            temp= temp->next;
        }
        return len;


    }
    ListNode* middleNode(ListNode* head) {\
    int length= getlen(head);
    if(length == 1) return head;

    int value= length/2;

    for(int i=1; i<value+1; i++){
        head= head->next;
    }
    return head;  
    }
};