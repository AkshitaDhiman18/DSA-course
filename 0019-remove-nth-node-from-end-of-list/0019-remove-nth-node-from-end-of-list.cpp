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

    /*int get_len(ListNode* head){
        int len=0;
        while(head != nullptr){
            len++;
            head= head->next;
        }
        return len;
    }*/


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //empty LL
        /*if(head == nullptr) return head;
        
        //agr single node linkelist hai aur n== 1 hai toh list empty hojega
        if(head->next== nullptr){
            if(n == 1){
            ListNode* temp= head;
            head= nullptr;
            delete temp;
            }
            return head;
        }
        int len= get_len(head);
        
        //remove head
        if(n==len){
            ListNode* temp= head;
            head= temp->next;
            temp->next== nullptr;
            delete temp;
            return head;
        }

        int value= len-n;

        ListNode* prev= head;

        int pos=1;
        while(pos < value){
            prev= prev->next;
            pos++;
        }

        ListNode* curr= prev->next;
        ListNode* forward= curr->next;
        curr->next= nullptr;
        prev->next= forward;

        return head;*/

        //optimal approach: dummynode + fast and slow pointer
        //empty LL
        if(head == nullptr) return head;
        //“Dummy node is used to handle the edge case where the head node itself needs to be deleted, allowing us to treat head deletion just like deletion of any other node.”
        ListNode* dummy= new ListNode(0);
        dummy->next= head;

        ListNode* slow= dummy;
        ListNode* fast= dummy;
        int count=1;

        while(count <= n){
            fast= fast->next;
            count++;
        }

        while(fast->next != nullptr){
            slow= slow->next;
            fast= fast->next;
        }

        ListNode* temp= slow;
        ListNode* curr= temp->next;
        ListNode* forward= curr->next;

        curr->next= nullptr;
        temp->next= forward;

        return dummy->next;
    }
};