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

    /*int getlen(ListNode* head){
        int len=0;
        ListNode* temp= head;
        while(temp != nullptr){
            len++;
            temp= temp->next;
        }
        return len;


    }*/

    ListNode* middleNode(ListNode* head) {
        //bruteforce approach:- use 0 ased index technique
    /*int length= getlen(head);
    if(length == 1) return head;

    int value= length/2;

    for(int index=0; index<value; pos++){
        head= head->next;
    }
    return head;*/

    //Tortoise-Hare approach

    ListNode* slow= head;
    ListNode* fast= head;

    while(fast != nullptr && fast->next != nullptr){
        slow= slow->next;
        fast= fast->next->next;
    }

    return slow;
    }
};