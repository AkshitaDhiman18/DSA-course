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

        //BRUTEFORCE APPROACH
        //agr LL empty ho toh uski nullptr hi deep copy bnegi 
        /*if(head == nullptr) return nullptr;

        //head ko 2 ways mein use krna hai 
        Node* preserve= head;
        Node* move= head;

        //dummy node bnyege for deep copy so what after all we can return our deep copy
        Node* dummy= new Node(0);
        //pt ko dummy pe point kryege 
        Node* pt= dummy;
        //ek temp node bnyege jo har original node ki deep copy node hai aur initially usme head ki value dalvyege
        Node* temp= new Node(move->val);
        //dummy ko join kredege is deep copy node temp se
        dummy->next= temp;

        //same process ham repet krege original mnode ki deep copy node bmnuege aur join krwate rhege
        while(move->next != nullptr){
            Node* next_node= new Node(move->next->val);
            temp->next= next_node;

            temp= temp->next;
            move= move->next;
            
        } 
        //last mein temp ka next nullptr ko point krega
        temp->next= nullptr;
        //pt dummy ke next ko fot further traversal for random pointer
        pt= dummy->next;

        //is step tk hamne next pointer shi se set krdiye h
        //ab bari h random pointer ki

        //2 new pointer bnyege to track random index for both the original LL and deep copy LL which we had made above
        Node* move_ptr= nullptr;
        Node* random_find= nullptr;

        //here preserve represents original LL and pt represents deep copy LL
        while(preserve != nullptr) {
            //if random pointer null ko pint kra h
            if(preserve->random == nullptr){
                pt->random= nullptr;
            }else{
                //aur agr kisi valid node ko kra h toh yeh
                Node* random_pointer= preserve->random;
                int i=0;
                random_find=head;

                //this one for origianl LL
                while(random_find != random_pointer){
                    i++;
                    random_find=random_find->next;
                }

                //this one for deep copy LL
                move_ptr= dummy->next;
                int j=0;
                while(j<i){
                    j++;
                    move_ptr= move_ptr->next;
                }

                pt->random= move_ptr;
            }
            //pointes movement to process new nodes
            preserve=preserve->next;
            pt= pt->next;
        }

        return dummy->next;*/

        //OPTIMAL SOLUTION-> INTERWEAVING
        if(head == nullptr) return nullptr;

        Node* temp= head;

        //insertion of nodes in between original nodes
        while(temp != nullptr){
            Node* new_node= new Node(temp->val);
            new_node->next= temp->next;
            temp->next= new_node;
            temp= temp->next->next;
        }

        //creation of random links 

        Node* move= head;
        while(move != nullptr){
            if(move->random==nullptr){
                move->next->random= nullptr;
            }else{
                move->next->random= move->random->next;
            }
            move= move->next->next;
        }

        //separation of original LL and deep copy LL
        Node* new_head= head->next;
        Node* curr= head;
        Node* new_curr= new_head;

        while(curr != nullptr && new_curr->next != nullptr){
            //original LL connection
            curr->next= curr->next->next;
            curr= curr->next;

            //for deep copy LL
            new_curr->next= new_curr->next->next;
            new_curr= new_curr->next;
        }

        curr->next= curr->next->next;
        new_curr->next= nullptr;

        return new_head;  
    }
};