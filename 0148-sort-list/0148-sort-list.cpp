/*
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
    ListNode* merge(ListNode* low, ListNode* next) {
        ListNode* left = low;
        ListNode* right = next;

        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;

        while (left != nullptr && right != nullptr) {
            int value1 = left->val;
            int value2 = right->val;

            if (value1 <= value2) {
                prev->next = left;
                prev = left;
                left = left->next;
            } else {
                prev->next = right;
                prev = right;
                right = right->next;
            }
        }

        // bacha hua part jod do
        if (left == nullptr) prev->next = right;
        else prev->next = left;

        ListNode* head = dummy->next;
        delete dummy;
        return head;                 // naya head return
    }

    ListNode* mergesort(ListNode* low, ListNode* high) {
        // sirf ek element bacha
        if (low == high) return low;

        ListNode* slow = low;
        ListNode* fast = low;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow = middle, next = middle ke baad wala node
        ListNode* next = slow->next;
        slow->next = nullptr;        // list ko do hisson mein todo

        ListNode* left  = mergesort(low, slow);    // sorted left ka head
        ListNode* right = mergesort(next, high);   // sorted right ka head

        return merge(left, right);   // merged ka head return
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* low = head;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
        }

        ListNode* high = tail;

        return mergesort(low, high);  // returned head hi answer hai
    }
};











/*class Solution {
public:
    ListNode* merge(ListNode* low, ListNode* next) {
        ListNode* left = low;
        ListNode* right = next;

        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;

        while (left != nullptr && right != nullptr) {
            int value1 = left->val;
            int value2 = right->val;

            if (value1 <= value2) {
                prev->next = left;
                prev = left;
                left = left->next;
            } else {
                prev->next = right;
                prev = right;
                right = right->next;
            }
        }

        // bacha hua part jod do
        if (left == nullptr) prev->next = right;
        else prev->next = left;

        ListNode* head = dummy->next;
        delete dummy;
        return head;                 // naya head return
    }

    ListNode* mergesort(ListNode* low, ListNode* high) {
        // sirf ek element bacha
        if (low == high) return low;

        ListNode* slow = low;
        ListNode* fast = low;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow = middle, next = middle ke baad wala node
        ListNode* next = slow->next;
        slow->next = nullptr;        // list ko do hisson mein todo

        ListNode* left  = mergesort(low, slow);    // sorted left ka head
        ListNode* right = mergesort(next, high);   // sorted right ka head

        return merge(left, right);   // merged ka head return
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        //bruteforce approach

        /*vector<int> arr;
        ListNode* temp= head;

        while(temp != nullptr){
            arr.push_back(temp->val);
            temp= temp->next;
        }

        sort(arr.begin(), arr.end());

        temp= head;
        int i=0;
        while(temp != nullptr){
            temp->val = arr[i];
            i++;
            temp= temp->next;
        }

        return head;

        ListNode* low= head;
        ListNode* tail= head;

        while(tail->next!= nullptr){
            tail= tail->next;
        }

        ListNode* high= tail;

        mergesort(head, low, high);

        return head;
        
    }
};*/
