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
    ListNode* reverseList(ListNode* head) {
        //bruteforce approach
        vector<int> arr;

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
        return head; 
    }
};