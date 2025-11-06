#include<iostream>
using namespace std;

struct Queue{
    int* arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        rear=0;
    }

    ~Queue() {   // destructor
    delete[] arr;
    }

    bool isFull(){
        return rear==size;
    }

    bool isEmpty(){
        return front==rear;
    }

    void enqueue(int data){
        if(isFull()){
            cout<<"Queue overflow..";
        }else{
            arr[rear]=data;
            rear++;
        }
    }


    void dequeue(){
        if(isEmpty()){
            cout<<"Queue underflow..";

        }
           
         front++;
         //this conditon only run when we delete all element from array , than reset it
        if(front==rear){  //means is Queue is empty  , than reset Queue
            front=0;
            rear=0;
        }
    }

    void qfront(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }else{
            cout<<"Front: "<<arr[front]<<endl;
        }
    }

    void qrear(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }else{
            cout<<"Rear: "<<arr[rear-1]<<endl;
        }
    }

    void display(){

        for(int i=front; i<rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};

int main(){
    Queue q(5);

    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    

    q.display();
    q.dequeue();

    q.qfront();
    q.qrear();


    return 0;
}