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



    return 0;
}