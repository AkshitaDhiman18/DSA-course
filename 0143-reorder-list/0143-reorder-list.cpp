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

        //edge cases
        if(head == nullptr || head->next == nullptr) return;

        //find middle
        ListNode* slow=head;
        ListNode* fast= head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow= slow->next;
            fast= fast->next->next;
        }

        //reverse second half

        ListNode* A= slow->next;
        slow->next= nullptr;
        ListNode* prev= nullptr;

        while(A != nullptr){
            ListNode* forward= A->next;
            A->next=prev;

            prev= A;
            A= forward;
        }

        //link attachment

        ListNode* temp= head;
        ListNode* middle= temp->next;

        while(middle != nullptr){
            ListNode* further= prev->next;
            ListNode* further1= middle->next;

            temp->next=prev;
            prev->next= middle;

            temp=middle;
            middle= further1;
            prev= further;
        }

        temp->next= prev;
        return;
    }
};