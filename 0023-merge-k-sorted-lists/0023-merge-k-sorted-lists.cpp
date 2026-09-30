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

    /*if(lists.empty()) return nullptr;
    
    int n= lists.size();
    if(n==1 && lists[0]==nullptr) return nullptr; 
    if(n==1) return lists[0];

    ListNode* dummy = new ListNode(0);
    dummy->next = lists[0];



    //size n ke liye merging n-1 br hogi
    for(int i = 1; i < lists.size(); i++) {

        ListNode* previous = dummy;
        ListNode* start1 = dummy->next;
        ListNode* start2 = lists[i];

        while(start1 != nullptr && start2 != nullptr) {

            if(start1->val <= start2->val) {
                previous = start1;
                start1 = start1->next;
            }
            else {
                ListNode* forward = start2->next;

                previous->next = start2;
                start2->next = start1;

                previous = start2;
                start2 = forward;
            }
        }

        if(start2 != nullptr) {
            previous->next = start2;
        }
    }

    return dummy->next;*/

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