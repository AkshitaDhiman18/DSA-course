/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* preserve= head;
        Node* move= head;

        Node* dummy= new Node(0);
        Node* pt= dummy;
        Node* temp= new Node(move->val);
        dummy->next= temp;


        while(move->next != nullptr){
            Node* next_node= new Node(move->next->val);
            temp->next= next_node;

            temp= temp->next;
            move= move->next;
            
        } 
        temp->next= nullptr;
        pt= dummy->next;
        Node* move_ptr= nullptr;
        Node* random_find= nullptr;


        while(preserve != nullptr) {
            if(preserve->random == nullptr){
                pt->random= nullptr;
            }else{
                Node* random_pointer= preserve->random;
                int i=0;
                random_find=head;

                while(random_find != random_pointer){
                    i++;
                    random_find=random_find->next;
                }

                move_ptr= dummy->next;
                int j=0;
                while(j<i){
                    j++;
                    move_ptr= move_ptr->next;
                }

                pt->random= move_ptr;
            }
            preserve=preserve->next;
            pt= pt->next;
        }

        return dummy->next;
    }
};