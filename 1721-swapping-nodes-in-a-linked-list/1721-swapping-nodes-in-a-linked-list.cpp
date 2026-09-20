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
    int get_size(ListNode* head){
        int size=0;
        ListNode* temp= head;
        while(temp != nullptr){
            temp= temp->next;
            size++;
        }
        return size;
    }

    ListNode* swapNodes(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* left= head;
        ListNode* right= head;

        int i=1;
        while(i<k){
            left= left->next;
            i++; 
        }

        int j=1;
        int size= get_size(head);

        while(j < size-k+1){
            right= right->next;
            j++;
        }

        int temp=left->val;
        left->val= right->val;
        right->val= temp;

        return head;
    }
};