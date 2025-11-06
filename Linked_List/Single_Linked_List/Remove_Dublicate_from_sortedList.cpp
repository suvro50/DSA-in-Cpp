#include<iostream>
using namespace std;

struct Node{

    int data;
    Node* next;
    Node( int data){
        this->data=data;
        next=nullptr;
    }
};

Node* Insert_last(Node* head,int data){
    Node* newnode=new Node(data);
    if(head==nullptr){
        head=newnode;
        return head;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }

    temp->next=newnode;
    return head;
}

Node* Remove_dublicate(Node* head){
    if (head==nullptr){
        return head;
    }
    Node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        if(temp->data==temp->next->data){

            Node* deletenode=temp->next;
            temp->next=temp->next->next;
            delete deletenode;
        }else{
            temp=temp->next;
        }
    }
    return head;

}

void print(Node* head){
    for(Node* i=head;i!=nullptr;i=i->next){
        cout<<i->data<<" ";
    }
    cout<<endl;
}

int main(){
    int n,val;
    Node* head=nullptr;

    cout<<"Enter node numbers: ";
    cin>>n;
    cout<<"Enter values: ";
    for(int i=0;i<n;i++){
        cin>>val;
        head=Insert_last(head,val);
    }

    print(head);

    cout<<"After remove dublicate: "<<endl;

    head=Remove_dublicate(head);
    print(head);
    return 0;


}