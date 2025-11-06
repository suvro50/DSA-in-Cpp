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

void print(Node* head){
    for(Node* i=head;i!=nullptr;i=i->next){
        cout<<i->data<<" ";
    }
    cout<<endl;
}

Node* insert_anywhere(Node* head, int pos,int val){
    Node* newnode=new Node(val);
    if(head==nullptr){
        return newnode;
    }

    if(pos==1){
        newnode->next=head;
        head=newnode;
        return head;
    }
    Node* temp=head;

    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }

    if(temp==nullptr|| pos<=0 || temp->next==nullptr){
        cout<<"postion out of the range"<<endl;
        delete newnode;
        return head;

    }

    newnode->next=temp->next;
    temp->next=temp->next->next;
    return head;
}

bool issorted(Node* head){
    if( head==nullptr || head->next==nullptr){
        return true;
    }

        Node* temp=head;
        while(temp->next!=nullptr){
            if(temp->data > temp->next->data){
                return false;
            }
            temp=temp->next;
        }
    return true;
}

int sumOf_element(Node* head){
    int sum=0;
    Node* temp=head;
    while(temp!=nullptr){
        sum+=temp->data;

        temp=temp->next;
    }
    return sum;
}

int main(){
    int n, val;
    Node* head=nullptr;

    cout<<"Enter how many node you want: ";
    cin>>n;
    
    cout<<"Enter valus: ";
    for(int i=0;i<n;i++){
        cin>>val;
        head=push_back(head,val);
    }

    print(head);

    head=insert_anywhere(head,2,0);
    print(head);

    cout<<endl<<"Linked list sum: ";
    cout<<sumOf_element(head)<<endl;
  

    if(issorted(head)){
        cout<<"List is sorted in ascending order.."<<endl;
    }else {
        cout<<"List isn't sorted.."<<endl;
    }
    return 0;
}