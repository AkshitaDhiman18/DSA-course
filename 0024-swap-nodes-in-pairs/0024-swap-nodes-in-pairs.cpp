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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy= new ListNode(0);
        dummy->next= head;
        ListNode* point= dummy;


        while(point->next != nullptr && point->next->next != nullptr){
            ListNode* first= point->next;
            ListNode* second= point->next->next;
            
            //swapping of 2 nodes
            first->next= second->next;
            second->next= first;

            point->next= second;
            point= first;
        }

        return dummy->next;

    }
};