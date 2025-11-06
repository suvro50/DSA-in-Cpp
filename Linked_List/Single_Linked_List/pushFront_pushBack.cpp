#include<iostream>
using namespace std;

struct Node{
     int data;  // store value 
     Node* next;  // pointer store address

     Node(int data){
        this->data=data;
        next=nullptr;
     }
};

struct List{
    Node* head;
    Node* tail;

    List(){
        head=tail=nullptr;
    }

    void push_front(int val){   // pust new element in first 
        Node* N=new Node(val);

        if(head==nullptr){
            head=tail=N;
            return ;
        }else{
            N->next=head;
            head=N;
        }
    }

    void push_back(int val){    // push new element in last

        Node* N=new Node(val);
            if(head==nullptr){
                head=tail=N;
                return;
            }else{
                tail->next=N;
                tail=N;
            }
        }



        void print(){
        for(Node* i=head;i!=nullptr;i=i->next){
            cout<<i->data<<" ";
        }
    }
};

int main(){

    List l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);

    l.push_back(5);
    l.push_back(6);

    l.print();

        return 0;
}
