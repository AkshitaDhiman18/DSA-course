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
        if(head == nullptr) return head; //if list is empty
        // Step 1: beginning se matching nodes remove karo
        //handlings consecutive matching nodes at the beginning of list are handled
        while(head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            temp->next= nullptr;
            delete temp;
        }

        // Step 2: baaki list traverse karo
        ListNode* curr = head;

        while(curr != nullptr && curr->next != nullptr) {

            if(curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = temp->next;
                temp->next= nullptr;
                delete temp;
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};
//temp pointer behaves as a node which we want to delete 
//curr pointer behaves as a prev of a node(temp) 