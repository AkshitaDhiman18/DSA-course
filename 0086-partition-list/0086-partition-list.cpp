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
 //List ko x ke basis par do groups mein arrange karo — pehle < x, phir >= x, while dono groups ke andar original order same rehna chahiye.
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        if(head == nullptr) return nullptr;
        

        ListNode* dummy= new ListNode(0);
        dummy->next= head;
        ListNode* point= dummy;

        ListNode* prev= new ListNode(0);
        ListNode* temp= point->next;
        ListNode* start= nullptr;

        //dummy= nullptr;
        int i=1;

        while(temp != nullptr){
            int value;
            value= temp->val;

            if(value < x){
                ListNode* forward= temp->next;
                temp->next= nullptr;
                point->next= temp;
                point= temp;
                temp= forward;
            }else if(value >= x){
                ListNode* forward1= temp->next;
                if(i == 1){
                    start= temp;
                    i++;
                }

                temp->next= nullptr;
                prev->next= temp;
                prev= temp;
                temp= forward1;
            }
        }
        point->next= start;
        return dummy->next;
    }
};