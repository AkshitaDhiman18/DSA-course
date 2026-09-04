/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        //bruteforce approach:- Hum List A ke saare node addresses/pointers set mein store kar rahe hain.
        //Then List B ko traverse karke check kar rahe hain ki koi node address already set mein hai ya nahi.
        /*unordered_set<ListNode*> stt;

        ListNode* temp1= headA;
        ListNode* temp2= headB;

        while(temp1 != nullptr){
            stt.insert(temp1);
            temp1= temp1->next;
        }

        while(temp2 != nullptr){
            if(stt.count(temp2)){
                return temp2;
            }
            temp2= temp2->next;
        }
        return nullptr;*/

        //optimal solution
        int size1= get_len(headA);
        int size2= get_len(headB);

        int difference= abs(size1-size2);
        if(difference > 0){
            if(size1 > size2){
                int i=0;
                while(i<difference){
                    headA= headA->next;
                    i++;
                }
            } else if(size2 > size1){
                int i=0;
                while(i<difference){
                    headB= headB->next;
                    i++;
                }
            }
        }

        ListNode* temp1= headA;
        ListNode* temp2= headB;

        while(temp1 != nullptr){
            if(temp1 == temp2) return temp2;
            temp1= temp1->next;
            temp2= temp2->next;
        }
        return nullptr;

    }
};