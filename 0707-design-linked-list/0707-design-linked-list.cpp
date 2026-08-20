//FOR SINGLY LINKEDLIST
//iska kaam bs node banana hai
/*class Node {
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
         //invalid index
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
        
        if(index < 0 || index > len) return;

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
};*/

//FOR DOUBLY LL
class node {
public:
    int val;
    node* next;
    node* prev;

    node(int data) {
        this->val = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class MyLinkedList {
public:
    node* head;
    node* tail;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get_len() {
        node* temp = head;
        int len = 0;

        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        return len;
    }

    int get(int index) {
        int len = get_len();

        if (index < 0 || index >= len)
            return -1;

        node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp->val;
    }

    void addAtHead(int val) {
        node* newnode = new node(val);

        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        }
        else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void addAtTail(int val) {
        node* newnode = new node(val);

        if (tail == nullptr) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void addAtIndex(int index, int val) {
        int len = get_len();

        if (index < 0 || index > len)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == len) {
            addAtTail(val);
            return;
        }

        node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        node* forward = temp->next;
        node* newnode = new node(val);

        temp->next = newnode;
        newnode->prev = temp;

        newnode->next = forward;
        forward->prev = newnode;
    }

    void deleteAtIndex(int index) {
        int len = get_len();

        if (index < 0 || index >= len)
            return;

        // Only one node
        if (len == 1) {
            node* temp = head;

            head = nullptr;
            tail = nullptr;

            delete temp;
            return;
        }

        // Delete head
        if (index == 0) {
            node* temp = head;

            head = head->next;
            head->prev = nullptr;

            delete temp;
            return;
        }

        // Delete tail
        if (index == len - 1) {
            node* temp = tail;

            tail = tail->prev;
            tail->next = nullptr;

            delete temp;
            return;
        }

        // Delete middle node
        node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        node* backward = temp->prev;
        node* forward = temp->next;

        backward->next = forward;
        forward->prev = backward;

        delete temp;
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