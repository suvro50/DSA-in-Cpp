#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=nullptr;
    }
};



void print(Node* head){
    for(Node* i=head; i!=nullptr;i=i->next){
        cout<<i->data<<" ";
    }
}

 Node* Insert_last( Node* head, int val){
    Node* newnode=new Node(val);

    if(head==nullptr){
        return newnode;
    }


    Node* temp=head;
    while( temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;

    return head;

 }

 Node* reverse_list(Node* head){
    Node* curr=head;
    Node* prev=nullptr;

    while(curr!=nullptr){
        Node* forword=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forword;
    }
    return prev;
 }

 Node* insert_anyposition(Node* head, int pos, int val){
    Node* newnode=new Node(val);
    if(head==nullptr){
        return newnode;
    }

    if(pos==1){
        newnode->next=head;
        head=newnode;
        return head;
    }

    Node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }

    if( temp->next==nullptr){
        cout<<endl<<"You gave null position"<<endl;
    }

    newnode->next=temp->next;
    temp->next=temp->next->next;
    return head;
    
 }

 Node* delete_any_positio(Node* head, int pos){

    if(head==nullptr){
        return head;
    }
    Node* temp=head;

    if(pos==1){
        head=head->next;
        delete temp;
    }

    
    
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    if(temp->next==nullptr){
        cout<<endl<<"null position"<<endl;
    }
    Node* deletenode=temp->next;
    temp->next=temp->next->next;
    delete deletenode;

    return head;
 }

 Node* delete_last(Node* head){
    if(head==nullptr){
        return head;
    }
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return head;
        
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){  
        temp=temp->next;
    }
    Node* deletenode=temp->next;
    temp->next=nullptr;
    delete deletenode;
    return head;
 }

int main(){

    Node* head=nullptr;

    head=Insert_last(head,1);
    head=Insert_last(head,2);
    head=Insert_last(head,3);
    head=Insert_last(head,4);
     head=Insert_last(head,5);
    
    print(head);

    head=insert_anyposition(head,1,10);
    cout<<endl<<"After Insert data: "<<endl;
    print(head);


    cout<<endl<<"After delete: "<<endl;
    head=delete_last(head);
    print(head);


    cout<<endl<<"After reverse linked list: "<<endl;
    head=reverse_list(head);
    print(head);




    return 0;
}




