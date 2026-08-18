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

        if(head == nullptr) return head;
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

        return head;
        
    }
};