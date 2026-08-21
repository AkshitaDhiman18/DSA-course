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
    bool isPalindrome(ListNode* head) {
        //bruteforce approach
       /*vector<int> arr;

       ListNode* temp= head;
       while(temp != nullptr){
        arr.push_back(temp->val);
        temp= temp->next;
       }
       ListNode* temp1= head;
       int size= arr.size();
       for(int i= size-1; i>=0; i--){
        if(arr[i] != temp1->val) return false;

        temp1= temp1->next;
       }

       return true;*/

       //Tortoise-Hare approach

       ListNode* slow= head;
       ListNode* fast= head;
       //middle find
       while(fast ->next != nullptr && fast->next->next != nullptr){
        slow= slow->next;
        fast= fast->next->next;
       }

       //reverse second half
       ListNode* newnode= slow->next;
       slow->next= nullptr;
       ListNode* prev= nullptr;

       while(newnode != nullptr){
        ListNode* forward= newnode->next;
        newnode->next= prev;
        prev= newnode;
        newnode=forward;
       }

       //compare
       ListNode* temp= head;
       ListNode* temp1= prev;

       while(temp1 != nullptr){
        if(temp->val != temp1->val){
            return false;
        }

        temp=temp->next;
        temp1= temp1->next;
       }

       return true;
    }
};