#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
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

Node* reverse(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL){
        Node* forword=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forword;
    }
    return prev;
}

bool palindrome(Node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node* fast=head->next;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    Node* secend_half=reverse(slow->next);
    Node* part1=head;
    Node* part2=secend_half;
    while(part2!=NULL){
        if(part1->data!=part2->data){
            return false;
        }
        part1=part1->next;
        part2=part2->next;

    }
    return true;
}

int main(){
    int n,val;
    Node* head=NULL;
    cout<<"Enter Number of nods: ";
    cin>>n;
    
    cout<<"Enter value: ";
    for(int i=0;i<n;i++){
        cin>>val;
        head=Insert_last(head,val);
    }

    cout<<( palindrome(head) ? "Yes" : "No");

    return 0;
}