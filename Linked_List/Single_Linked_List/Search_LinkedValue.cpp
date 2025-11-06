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

int search(int key){
    if(head==nullptr){
        return -1;
    }
    int count=0; // linked list don't have index , so make count , for counting index
    for(Node* i=head;i!=nullptr;i=i->next){
        if(i->data==key){
           return count;
        }
        count++;
    }
    return -1;

}  


void print(){
    for(Node* i=head;i!=nullptr;i=i->next){
        cout<<i->data<<" ";
    }
}


int main(){

    push_front(5);
    push_front(6);
    push_front(4);

    push_back(8);
    push_back(10);
    print();

    ll_length();

   int result=search(6);

   cout<<endl<<"Index of 6 is "<<result;

    return 0;
}