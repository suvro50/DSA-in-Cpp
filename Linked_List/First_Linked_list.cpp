#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    // Node(int date){
    //     this->data=data;
    //     next=NULL;
    // }

};

struct list{
   Node* head;
   Node* tail;

   list(){
    head=tail=nullptr;
   }

   void push_front(int val){
       Node* n1=new Node(val);

       if(head==nullptr){
        head=tail=n1;
        return;
       }else{
        n1->next=head;
        head=n1;
       }

   }

};

int main(){

    Node* block1=new Node();
    block1->data=5;
    block1->next=nullptr;

    Node* block2=new Node();
    block2->data=6;
    block2->next=nullptr;

    Node* block3=new Node();
    block3->data=7;
    block3->next=nullptr;

    // Linking nodes

    block1->next=block2;
    block2->next=block3;

    cout<<block1->next->next->data;


     // Free memory
    delete block1;
    delete block2;
    delete block3;


    return 0;
}