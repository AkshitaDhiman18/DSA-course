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

   /*int get_len(ListNode* head){
    int len=0;
    while(head != nullptr){
        len++;
        head= head->next;
    }
    return len;
   }*/



    void reorderList(ListNode* head) {
        //bruteforce approach
        /*int len= get_len(head);
        //edge cases
        if(head == nullptr || head->next == nullptr) return;

        //middle nikalo
        ListNode* slow=head;
        ListNode* fast= head;
        int middle_index=0;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow= slow->next;
            middle_index+=1;
            fast= fast->next->next;
        }

        //elements insertion in vector
        vector<int> arr;
        ListNode* A= slow->next;
        while(A!= nullptr){
            arr.push_back(A->val);
            A= A->next;
        }

        //disconnect connection
        slow->next = nullptr;

        int size= arr.size();
        int i= size-1;

        //linking
        ListNode* prev= head;
        ListNode* curr= prev->next;
        int index=0;
        while(index < middle_index){
            ListNode* forward= curr->next;
            ListNode* new_node= new ListNode(arr[i]);

            prev->next= new_node;
            new_node->next= curr;

            prev= curr;
            curr= forward;

            index++;
            i--;
        }

        if(len % 2 == 0){
            ListNode* lastNode= new ListNode(arr[i]);
            prev->next= lastNode;
            lastNode->next= nullptr;

        }else{
            prev->next= nullptr;
        }*/

        //optimal approach

        // Edge cases
        if (head == nullptr || head->next == nullptr)
            return;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* new_head = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while (new_head != nullptr) {
            ListNode* forward = new_head->next;

            new_head->next = prev;
            prev = new_head;
            new_head = forward;
        }

        // Merge two halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second != nullptr) {

            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
        return;
    }
};