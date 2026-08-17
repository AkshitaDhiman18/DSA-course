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
    ListNode* oddEvenList(ListNode* head) {
        //bruteforce approach
        vector<int> arr;

    if(head == nullptr) return head;

    

    ListNode* temp= head;
    //for odd values
    while(temp != nullptr && temp->next != nullptr){
        arr.push_back(temp->val);
        temp= temp->next->next;

    }
    if(temp != nullptr) arr.push_back(temp->val);
    

    //for even nodes
    ListNode* temp1= head->next;
    while(temp1 != nullptr && temp1->next != nullptr){
        arr.push_back(temp1->val);
        temp1= temp1->next->next;
    }
    if(temp1 != nullptr) arr.push_back(temp1->val);

    ListNode* a= head;
    int Size= arr.size();
    int i=0;
    while(a != nullptr){
        if(a->val != arr[i]){
            a->val = arr[i];
        }
        a= a->next;
        i++;
    }
    return head;
    }
};