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
    int get_len(ListNode* head){
        int len=0;
        while(head != nullptr){
            len++;
            head= head->next;
        }
        return len;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> arr(k,nullptr);

        if(head == nullptr) return arr;

        ListNode* start= head;


        int length= get_len(head);

        int mandatory;
        int remaining;
        if(length < k){
            mandatory = 1;
            remaining=0;
        }else{
            mandatory= length / k;
            remaining= length % k;
        }
        
        int value;
        int i=0;
        
        while(i<k && start != nullptr){
            if(remaining > 0){
                value= mandatory + 1;
                remaining-=1;
            }else{
                value= mandatory;
            }

            ListNode* temp= start;
            int j=1;
            while(j<value){
                temp= temp->next;
                j++;
            }

            ListNode*forward= temp->next;
            temp->next= nullptr;

            arr[i]=start;
            start= forward;
            i++;
        }
        return arr;
    }
};