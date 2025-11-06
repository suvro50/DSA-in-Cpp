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

Node* front;
Node* rear;

struct Queue{

    Queue(){
        front=nullptr;
        rear=nullptr;
    }


    bool isEmpty(){
        return (front==nullptr && rear==nullptr);
    }

    void front_rear(){
        if(isEmpty()){
            cout<<"Queue is empty.."<<endl;
            return;
        }
        cout<<front->data<<endl;
        cout<<rear->data<<endl;
    }
    
    void enqueue(int val){
        Node* temp=new Node(val);

        if(isEmpty()){
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue underflow.."<<endl;
            return;
        }

         if(front==rear){  // if Queue have only one element ..
            front=rear=nullptr;
            return;
        }

        
        Node* temp=front;
        front=front->next;
        delete temp;
    }

    void print(){

        for(Node* i=front;i!=nullptr;i=i->next){
            cout<<i->data<<" ";
        }
        cout<<endl;
    }

};

int main(){

    Queue q;

    q.enqueue(4);
    q.enqueue(10);
    q.enqueue(21);
   q.dequeue();

   
    q.print();
    q.front_rear();



    return 0;
}