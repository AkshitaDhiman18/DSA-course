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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        // Step 1: beginning se matching nodes remove karo
        while(head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // Step 2: baaki list traverse karo
        ListNode* curr = head;

        while(curr != nullptr && curr->next != nullptr) {

            if(curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};