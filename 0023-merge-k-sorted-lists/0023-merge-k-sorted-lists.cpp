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

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy= new ListNode(0);
        ListNode* pt= dummy;

        while(left != nullptr && right != nullptr){
            int v1= left->val;
            int v2= right->val;

            if(v1 <= v2){
                pt->next= left;
                pt=left;
                left=left->next;
            }else{
                pt->next= right;
                pt= right;
                right=right->next;
            }
        }

        if(left == nullptr){
            pt->next= right;
        }else{
            pt->next= left;
        }

        ListNode* head= dummy->next;
        dummy->next= nullptr;
        delete dummy;
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    int size= lists.size();

    if(size == 0 || (size == 1 && lists[0] == nullptr)) return nullptr;
    if(size == 1) return lists[0];

    ListNode* left= lists[0];

    int i=1;
    while(i < size){
        ListNode* right= lists[i];
        left= merge(left, right);
        i++;
    }

    return left;
}
};