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

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len= get_len(head);
        int grps= len/k;

        ListNode* dummy= new ListNode(0);
        dummy->next= head;

        ListNode* point= dummy;
        ListNode* temp= point->next;

        int i=1;
        while(i<=grps){
            ListNode* complete= point->next;
            point->next= nullptr;
            ListNode* prev= nullptr;

            int size=1;
            while(size<=k){
                ListNode* forward= temp->next;
                temp->next= prev;
                prev= temp;
                temp=forward;
                size++;
            }

            point->next= prev;
            point=complete;
            point->next= temp;
            i++;
        }

        return dummy->next;
        
    }
};