/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Node{
    int data;
    Node* next;

    Node(int __d){
        this->data= __d;
        this->next= nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> stt;

        ListNode* temp1= headA;
        ListNode* temp2= headB;

        while(temp1 != nullptr){
            stt.insert(temp1);
            temp1= temp1->next;
        }

        while(temp2 != nullptr){
            if(stt.count(temp2)){
                return temp2;
            }
            temp2= temp2->next;
        }
        return nullptr; 
    }
};