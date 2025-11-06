#include<iostream>
using namespace std;


struct CircularQueue{
    int* arr;
    int size;
    int front;
    int rear;

    CircularQueue(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    ~CircularQueue(){
        delete[] arr;
    }


    bool isFull(){
        return ((rear+1)%size==front);
    }

    bool isEmpty(){
        return (front==-1 && rear==-1);
    }

    void qfront_rear(){
        if(isEmpty()){
            cout<<"Queue underflow.."<<endl;
        }
        cout<<"Front: "<<arr[front]<<endl;
        cout<<"Rear: "<<arr[rear]<<endl;
    }

    void enqueue(int data){
        if(isFull()){
            cout<<"Queue overflow.."<<endl;
            return;
        }

        if(isEmpty()){
         front=rear=0;   //when enter first element
         arr[rear] = data;
        }
        else{
        rear= (rear+1) % size;  // rear shift next index , or  circular move
        arr[rear]=data;
      

        }

    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue underflow.."<<endl;
            return;
        }
        if(front==rear){  // For single element , in index=0 front==rear
            front=rear=-1;
            return;
        }
        front=(front+1)%size;  // front move circuler

    }

    void print(){

       int i=front;
       while(true){
        cout<<arr[i]<<" ";
        if(i==rear) break;  // when print rear element than break
        i=(i+1) % size;
       }
        cout<<endl;
    }

};

int main(){

    CircularQueue q(4);

    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(20);

       
    q.print();
    q.qfront_rear();
    

    q.dequeue();
    q.print();
    q.qfront_rear();
    

    return 0;
}