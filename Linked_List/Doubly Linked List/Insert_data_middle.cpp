#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data=data;
        prev=next=nullptr;
       
    }
};

Node* head=nullptr;
Node* tail=nullptr;


void push_front(int val){
     Node* newnode=new Node(val);

    if(head==nullptr){
        head=tail=newnode;
        return;
    }

    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void push_back(int val){
    Node* newnode=new Node(val);

     if(head==nullptr){
        head=tail=newnode;
        return;
    }

    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;

}


void insert_middle(int pos,int val){
    Node* newnode=new Node(val);
    if(pos==1){
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return;
    }
    Node* temp=head;

    if(temp==nullptr){
        cout<<"Invalid position -1";
        delete newnode;
        return;
    }

    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
   
   if(temp->next==nullptr){
   temp->next=newnode;
   newnode->prev=temp;
   tail=newnode;
   return;

   }
    // Insert in middle
   newnode->next=temp->next;
   temp->next->prev=newnode;

   temp->next=newnode;
   newnode->prev=temp;
}


 void print(){ 
   for(Node* i=head;i!=nullptr;i=i->next){
        cout<<i->data<<" ";
   }
    

}


int main(){

    push_front(4);
    push_front(3);
    push_front(2);

    push_back(6);
    push_back(8);

    print();

    cout<<endl<<"AFter insert: "<<endl;

    insert_middle(7,15);
    print();

    return 0;
}