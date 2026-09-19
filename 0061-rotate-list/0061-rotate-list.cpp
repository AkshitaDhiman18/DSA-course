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
        if(head->next == nullptr) return head;

        int len= get_len(head);

        int rotation= k % len;
        if(rotation == 0) return head;

        ListNode* tail= head;

        while(tail->next != nullptr){
            tail= tail->next;
        }

        ListNode* dummy= new ListNode(0);
        ListNode* prev= head;
        //ListNode* temp= dummy->next;

        int i=1;
        while(i < len-rotation){
            prev= prev->next;
            i++;
        }

        ListNode* forward= prev->next;
        prev->next= nullptr;

        dummy->next= forward;
        tail->next= head;

        return dummy->next;

    }
};


