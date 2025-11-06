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

Node* push_back(Node* head,int val){
    Node* newnode=new Node(val);
    if(head==nullptr){
        return newnode;
    }

    Node* temp=head;

    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

Node* remove_given_value(Node* head, int val){
    Node* dublicate=new Node(-1);
    dublicate->next=head;

    Node* curr=dublicate;

    while(curr->next!=nullptr){

        if(curr->next->data==val){
            curr->next=curr->next->next;
        }else{
            curr=curr->next;
        }
    }
    return dublicate->next;

}



void print(Node* head){
    for(Node* i=head;i!=nullptr;i=i->next){
        cout<<i->data<<" ";
    }
}

int main(){
    Node* head=nullptr;

    head=push_back(head,1);
    head=push_back(head,2);
    head=push_back(head,2);
    head=push_back(head,4);

    print(head);

    cout<<endl<<"After remove dublicate: "<<endl;
    head=remove_given_value(head,2);

    print(head);

    return 0;
}