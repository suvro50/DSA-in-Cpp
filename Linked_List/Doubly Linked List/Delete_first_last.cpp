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

void delete_first(){
    if(head==nullptr){
        cout<<"No data avalable";
        return;
    }

    if(head==tail){
        delete head;
        head=tail=nullptr;
        return;
    }

    Node* temp=head;
    head=head->next;
    head->prev=nullptr; 
    delete temp;

}

void delete_last(){

     if(head==nullptr){
        cout<<"No data avalable";
        return;
    }

    if(head==tail){
        delete head;
        head=tail=nullptr;
        return;
    }

    //O(1)  time complexcity

    Node* temp=tail;
    tail=tail->prev;
    tail->next=nullptr;  //here tail is alrady updated in tail->prev
   
    delete temp;
   
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
    cout<<endl<<"After delete 1st node "<<endl;

    delete_first();
    print();

    delete_last();

    cout<<endl;
    print();



    return 0;
}