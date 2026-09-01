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
            head= head->next;
            len++;
        }
        return len;
    }

     ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;

        int len= get_len(head);

        int rotation= k % len;
        if(rotation == 0) return head;

        ListNode* tail= head;

        while(tail->next != nullptr){
            tail= tail->next;
        }

        ListNode* dummy= new ListNode(0);
        dummy->next= head;

        ListNode* prev= dummy;
        ListNode* temp= dummy->next;

        int i=0;
        while(i < len-rotation){
            temp= temp->next;
            prev= prev->next;
            i++;
        }

        prev->next= nullptr;

        dummy->next= temp;
        tail->next= head;

        return dummy->next;    
    }
};


