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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //bruteforce approach

        /*if(head == nullptr) return head;
        if(left == right) return head;
        ListNode* temp= head;
        vector<int> arr;
        int pos=1;
        while(pos != left){
            temp= temp->next;
            pos++;
        }
        ListNode* insert= temp;

        while(pos != right){
            arr.push_back(temp->val);
            temp= temp->next;
            pos++;
        }
        arr.push_back(temp->val);
        
        int size= arr.size();
        for(int i=size-1; i>=0; i--){
           insert->val= arr[i];
           insert= insert->next;
        }

        return head;*/
        if(left == right || head == nullptr) return head;
        /*ListNode* temp= head;
        int pos=1;*/

         // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // temp ko left se just pehle le jao
        ListNode* temp = dummy;
        int pos = 1;

        while(pos < left) {
            temp = temp->next;
            pos++;
        }
        /*while(pos != left-1){
            temp= temp->next;
            pos++;
        }*/
        
        ListNode* curr= temp->next;
        ListNode* insert= curr;
        ListNode* prev= nullptr;
        temp->next= nullptr;

        while(pos <= right){
            ListNode* forward= curr->next;
            curr->next= prev;
            prev= curr;
            curr= forward;
            pos++;
        }

        temp->next=prev;
        insert->next=curr;

        return dummy->next;
    }
};