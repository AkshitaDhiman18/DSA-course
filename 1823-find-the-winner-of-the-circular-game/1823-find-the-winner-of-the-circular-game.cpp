class Node{
public:
    int value;
    Node* next;

    Node(int __v){
        this->value= __v;
        this->next= nullptr;
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        //CIRCULAR LL CREATION
        int i=1;
        Node* dummy= new Node(0);
        Node* pt= dummy;

        while(i<=n){
            Node* temp= new Node(i);
            pt->next= temp;
            pt= pt->next;
            i++;
        }

        Node* head=dummy->next;
        dummy->next= nullptr;
        pt->next= head;
        

        //NOW GAME STARTS
        Node* temp= head;
        Node* preserve= pt;
        

    while(preserve != temp){
        int i=1;
        while(i<k){
            temp= temp->next;
            preserve= preserve->next;
            i++;
        }
        Node* forward= temp->next;
        preserve->next= forward;
        temp->next= nullptr;
        delete temp;
        temp= forward;
    }

    int winner= preserve->value;
    return winner;
    }
};