class MyCircularDeque {
public:
    class Node{
        public:
        int val;
        Node* prev;
        Node* next;
        Node(){
            val=0;
            prev=NULL;
            next=NULL;
        }
        Node(int a){
            this->val=a;
            this->prev=NULL;
            this->next=NULL;
        }
    };
    int maxsize;
    int a=0;
    Node* head;
    Node* tail;
    MyCircularDeque(int k) {
        maxsize=k;
        head =new Node(INT_MAX);
        tail =new Node(INT_MIN);
        head->next=tail;
        tail->prev=head;
    }
    
    bool insertFront(int value) {
        if(a==maxsize){
            return false;
        }
        Node* temp=new Node(value);
        temp->next=head->next;
        head->next->prev=temp;
        head->next=temp;
        temp->prev=head;
        a++;
        return true;
    }
    
    bool insertLast(int value) {
        if(a==maxsize){
            return false;
        }
        Node* temp=new Node(value);
        temp->prev=tail->prev;
        tail->prev->next=temp;
        tail->prev=temp;
        temp->next=tail;
        a++;
        return true;
    }
    
    bool deleteFront() {
        if(a==0){
            return false;
        }
        a--;
        Node* temp = head->next;
        head->next=head->next->next;
        head->next->prev=head;
        delete temp;
        return true;
    }
    
    bool deleteLast() {
        if(a==0){
            return false;
        }
        a--;
        Node* temp = tail->prev;
        tail->prev=tail->prev->prev;
        tail->prev->next=tail;
        delete temp;
        return true;
    }
    
    int getFront() {
        if(a==0){
            return -1;
        }
        return head->next->val;
    }
    
    int getRear() {
        if(a==0){
            return -1;
        }
        return tail->prev->val;
    }
    
    bool isEmpty() {
        if(head->next==tail){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(a==maxsize){
            return true;
        }
        return false;
    }
};

/*
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */