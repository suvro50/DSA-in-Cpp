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
Node* head=nullptr;
Node* tail=nullptr;



    void push_back(int val){
        Node* newnode=new Node(val);

        if(head==nullptr){
            head=tail=newnode;
            return;
        }
        tail->next=newnode;
        tail=newnode;

    }

    void print(Node* head){
        for(Node* i=head;i!=nullptr;i=i->next){
            cout<<i->data<<" ";
        }
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


 int main(){

   //Node* head=nullptr;

    push_back(1);
    push_back(2);
    push_back(3);
    push_back(4);
    

    print(head);


    head=reverse_list(head);
    cout<<endl<<"After reverse list:"<<endl;
    print(head);

    return 0;
    
}