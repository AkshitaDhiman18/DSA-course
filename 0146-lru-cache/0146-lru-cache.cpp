class Node{
public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int __key, int __value){
        this->key= __key;
        this->value= __value;

        this->prev= nullptr;
        this->next= nullptr;
    }
};


void addatMRUpos(Node* &tail, Node* &newnode){
    Node* temp= tail->prev;
    newnode->next= tail;
    newnode->prev= temp;
    temp->next= newnode;
    tail->prev= newnode;

    return;
}

void deleteNodeFromLL(Node* &oldnode){
    Node* prev_of_oldnode= oldnode->prev;
    Node* next_of_oldnode= oldnode->next;

    prev_of_oldnode->next= next_of_oldnode;
    next_of_oldnode->prev= prev_of_oldnode;
    return;
}


class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;

    //key → Node ka address
    unordered_map<int, Node*> mp;


    LRUCache(int capacity) {
        this->capacity= capacity;

        head= new Node(-1, -1);
        tail= new Node(-1, -1);

        head->next= tail;
        tail->prev= head;
    }
    
    int get(int key) {
        int ans;
        if(mp.count(key)){
            Node* oldnode= mp[key];
            deleteNodeFromLL(oldnode);
            addatMRUpos(tail, oldnode);

            ans= oldnode->value;
        }else{
            return -1;
        }

        return ans;
    }
    
    void put(int key, int value) {
        //key exists
        if(mp.count(key)){
            Node* oldnode= mp[key];

            oldnode->value= value;
            deleteNodeFromLL(oldnode);
            addatMRUpos(tail, oldnode);
            return;
        }
//If capacity is zero, the cache cannot store any element, so I immediately return from put() to avoid trying to remove the dummy head/tail nodes.”
        if(capacity == 0){
            return;
        }

        //capacity check
        if(mp.size() == capacity){
            Node* oldnode= head->next;
            mp.erase(oldnode->key);
            deleteNodeFromLL(oldnode);
            delete oldnode;
        }

        //create new node
        Node* newnode= new Node(key, value);
        addatMRUpos(tail, newnode);
        mp[key]= newnode;

        return; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */