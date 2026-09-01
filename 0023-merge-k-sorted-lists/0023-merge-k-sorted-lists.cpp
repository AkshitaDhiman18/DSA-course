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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) return nullptr;

        int n= lists.size();

        if(n==1 && lists[0]==nullptr) return nullptr;
        if(n==1) return lists[0];

        ListNode* temp1= lists[0];
        ListNode* temp2= lists[1];

        ListNode* dummy= new ListNode(0);
        dummy->next= lists[0];

        ListNode* prev= dummy;
        while(temp1 != nullptr && temp2 != nullptr){
            int value1= temp1->val;
            int value2= temp2->val;

            if(value1 <= value2){
                prev=temp1;
                temp1=temp1->next;
            }else if(value2 < value1){
                ListNode* forward= temp2->next;
                temp2->next= nullptr;
                prev->next= temp2;
                temp2->next= temp1;

                prev= temp2;
                temp2=forward;
            }
        }

        if(temp2 != nullptr){
            prev->next= temp2;
        }

        int i=2;
        while(i<n){
            ListNode* previous= dummy;
            ListNode* start1= dummy->next;
            ListNode* start2= lists[i];

            while(start1 != nullptr && start2 != nullptr){
                int value1= start1->val;
                int value2= start2->val;
                
                if(value1 <= value2){
                previous=start1;
                start1=start1->next;
            }else if(value2 < value1){
                ListNode* forward= start2->next;
                start2->next= nullptr;
                previous->next= start2;
                start2->next= start1;

                previous= start2;
                start2=forward;
            }
        }

            if(start2 != nullptr){
                previous->next= start2;
            }
            i++;
        }

        ListNode* head=dummy->next;
        return head;
    }
};