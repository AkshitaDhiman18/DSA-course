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
       vector<int> arr;

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

       return true;
    }
};