#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        next=NULL;
    }

    ~node() {
        int value = this -> data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
void addAtTail(node* &tail, int val){
    node* n=new node(val);
    tail->next=n;
    tail=n;
}
void addAtHead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void addAtPosition(node* &head, node* &tail, int pos, int val){
    if(pos==1){
        addAtHead(head, val);
        return;
    }
    node* temp= head;
    int count=1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        addAtTail(tail, val);
        return;
    }
    node* n=new node(val);
    n->next=temp->next;
    temp->next=n;
}
void deleteNode(node* head, int pos){
    if(pos==1){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node* curr=head;
        node* prev=NULL;
        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main()
{
    node* n1=new node(10);
    node* head=n1;
    node* tail=n1;
    addAtTail(tail, 50);
    addAtTail(tail, 500);
    addAtTail(tail, 5021);
    addAtTail(tail, 50515);
    addAtTail(tail, 50545);
    addAtHead(head,50);
    addAtHead(head,512);
    addAtHead(head,5084);
    addAtHead(head,50323);
    display(head);

    deleteNode(head, 5);
    display(head);
    return 0;
}
