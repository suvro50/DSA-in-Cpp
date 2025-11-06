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


//Globaly deceleard head & tail..
Node* head=nullptr;
Node* tail=nullptr;



void push_front(int data){
    Node* newnode=new Node(data);
    if(head==nullptr){
       head=tail=newnode;
       return;
    }
    newnode->next=head;
    head=newnode;
}


void push_back(int data){
    Node* newnode=new Node(data);
    if(head==nullptr){
        head=tail=newnode;
        return;
    }
    tail->next=newnode;
    tail=newnode;
}



void ll_length(){
    int count=0;
    for(Node* i=head;i!=nullptr;i=i->next){
        count++;
    }
    cout<<endl<<"Length of the linked_list: "<<count;
}


void print(){
    for(Node* i=head;i!=nullptr;i=i->next){
        cout<<i->data<<" ";
    }
}




Node* middle_ll(){
    Node* fast=head->next;
    Node* slow=head;

    while(fast!=nullptr && fast->next!=nullptr){

        slow=slow->next;
        fast=fast->next->next;
  }
  return slow;

}

int main(){

    push_front(5);
    push_front(6);
    push_front(4);

    push_back(8);
    push_back(10);
    push_back(12);
    print();

    ll_length();


   Node* mid=middle_ll();

   cout<<endl<<"Middle of the linked list is: "<<mid->data;

    return 0;
}