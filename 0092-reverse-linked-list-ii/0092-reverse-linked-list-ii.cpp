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


        //kuch reverse nh krna
        //empty node
        if(left == right || head == nullptr) return head;

         // Dummy node
        ListNode* dummy = new ListNode(0); //dummy node whose value is 0
        //we used dummy to handle left == 1 case
        dummy->next = head;

        // temp ko left se just pehle le jao
        ListNode* temp = dummy; //kyuki hme temp ko left se just phele rkhna hai 
        int pos = 1;
        //temp ko left se just pehle rakhna hai.
        while(pos < left) {
            temp = temp->next;
            pos++;
        }
        
        ListNode* curr= temp->next;
        ListNode* insert= curr;
        ListNode* prev= nullptr;
        temp->next= nullptr;
        //right tk reverse kra
        while(pos <= right){
            ListNode* forward= curr->next;
            curr->next= prev;
            prev= curr;
            curr= forward;
            pos++;
        }

        temp->next=prev;
        insert->next=curr;
        //Aur dummy ka purpose hi ye hai ki head change hone wale cases (left == 1) ko easily handle kar sake.
        return dummy->next;
    }
};