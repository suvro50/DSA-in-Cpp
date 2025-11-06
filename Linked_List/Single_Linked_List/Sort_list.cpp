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

Node* findmid(Node* head){
    Node* fast=head->next;  
    Node* slow=head;
    while( fast!=nullptr && fast->next!=nullptr ){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node* merge_Two_part(Node* left,Node* right){
    if(left==nullptr){
        return right;
    }

     if(right==nullptr){
        return left;
    }

    Node* ans=new Node(-1);
    Node* temp=ans;

    //merge to sorted linked list
    while(left!=nullptr && right!=nullptr){
        if(left->data<right->data){
            temp->next=left;
            temp=left;
            left=left->next;

        }else{

            temp->next=right;
            temp=right;
            right=right->next;
        }
    }

    //if left list not finish 

    while(left!=nullptr){
        temp->next=left;
        temp=left;
        left=left->next;
    }

    // if right list not finish 
    while( right!=nullptr){
        temp->next=right;
        temp=right;
        right=right->next;
    }

    ans=ans->next;
    return ans;

}
Node* mergesort(Node* head){

    if(head==nullptr || head->next==nullptr){
        return head;
    }

    Node* mid=findmid(head);

    Node* left=head;
    Node* right=mid->next;
    mid->next=nullptr;

    // sort 2 different list
    left=mergesort(left);
    right=mergesort(right);

    Node* result=merge_Two_part(left,right);

    return result;
}

int main(){
    Node* head=nullptr;
    
    head=push_back(head,2);
    head=push_back(head,5);
    head=push_back(head,4);
    head=push_back(head,9);

    print(head);

    cout<<"Sorted list: ";

    head=mergesort(head);
    print(head);

    return 0;
}