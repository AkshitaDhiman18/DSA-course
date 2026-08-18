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
    ListNode* reverseLL(ListNode* head, ListNode* prev, ListNode* curr){
        //base case
        if(curr == nullptr){
            head= prev;
            return head;
        }

        ListNode* forward= curr->next;
        curr->next= prev;
        prev=curr;
        curr=forward;
        
        //recursive call
        return reverseLL(head,prev,curr);
    }

    ListNode* reverseList(ListNode* head) {
        //bruteforce approach
        /*vector<int> arr;

        ListNode* temp= head;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp= temp->next;
        }
        int size= arr.size();
        ListNode* a= head;
        for(int i= size-1; i>=0; i--){
            a->val= arr[i];
            a= a->next;
        }
        return head;*/

        //iterative approch
        /*ListNode* prev= nullptr;
        ListNode* curr= head;

        while(curr != nullptr){
            ListNode* forward= curr->next;
            curr->next= prev;
            prev= curr;
            curr=forward;
        }
        head= prev;
        //tail=temp;

        return head;*/

        //recursive approach

        ListNode* prev= nullptr;
        ListNode* curr= head;

        return reverseLL(head,prev,curr);

    }
};