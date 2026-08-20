//iska kaam bs node banana hai
class Node {
public:
    //node data memeber
    int val;
    Node* next;

    //constructor
    Node(int value){
        this->val= value;
        this->next= nullptr;
    }
};

//Ab humein poori linked list ko manage karna hai
class MyLinkedList {
public:
    //head ek pointer hai jo first Node ka address store karega.
    //head aur tail khud nodes nahi hain.
    //Ye nodes ke addresses store karne wale pointers hain.
    Node* head;
    Node* tail;

    MyLinkedList() {
        this->head= nullptr;
        this->tail= nullptr;
    }

    int get_len(Node* head){
        Node* a= head;
        int len =0;
        while(a!= nullptr){
            len++;
            a= a->next;
        }
        return len;
    }
    
    int get(int index) {
    int len= get_len(head);
         //ivalid index
        if(index <0 || index >= len) return -1;

            Node* temp= head;
            if(index == 0){
                return head->val;
            }else{
                int pos=0;
                while(pos != index){
                    pos++;
                    temp= temp->next;
                }
                return temp->val;
            }
        }

    void addAtHead(int val) {
        Node* new_node= new Node(val);
        if(head == nullptr){
            //empty linkedlist
            head= new_node;
            tail= new_node;
        }else{
            new_node->next= head;
            head= new_node;
        }
    }
    
    void addAtTail(int val) {
        Node* new_node= new Node(val);
        if(tail == nullptr){
            tail=new_node; 
            head= new_node; 
        }else{
            tail->next= new_node;
            tail=new_node;
        } 
    }
    
    void addAtIndex(int index, int val){
        int len= get_len(head);
        
        if(index > len) return;

        if(index == 0){
            addAtHead(val);
             return;
        }

        if(index == len){
            addAtTail(val);
            return;
        }

        Node* temp= head;
        Node* new_node= new Node(val);
        for(int i=1; i<index; i++){
            temp= temp->next;
        }

        Node* curr= temp->next;
        temp->next= new_node;
        new_node -> next= curr;  
    }
        

    
    void deleteAtIndex(int index) {
        int len= get_len(head);

        if(index < 0 || index >= len) return;

        Node* temp= head;
        // delete head
        if(index == 0) {

        head = head->next;
        delete temp;

        // list empty ho gayi
        if(head == nullptr) {
            tail = nullptr;
        }

        return;
        }

        
        for(int i=1; i<index; i++){
            temp= temp->next;
        }

        Node* curr= temp->next;
        Node* forward= curr->next;

        curr->next= nullptr;
        temp->next=forward;
        //Agar jo node delete ho rahi hai woh tail thi, toh tail ko previous node banana padega.
        if(curr == tail) {
        tail = temp;
    }
        delete curr;
    }    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */