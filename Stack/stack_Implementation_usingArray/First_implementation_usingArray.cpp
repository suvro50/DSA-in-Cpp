#include<iostream>
#include<stack>
using namespace std;

struct Stack{
    int* arr; // memory allocate in heap
    int top;    // array indexing
    int size;

    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    //destructor
    ~Stack(){    // delete data from heap memory
        delete[] arr;
    }

    void push(int element){
        if(top<size-1){ // check space avalable or not
            top++;
            arr[top]=element;  // top++ , so top=0 .;;, so arr[0]=element

        }else {
            cout<<"Stack Overflow to implement: "<<element<<endl;
        }
    }
    

    void pop(){
        if(top>=0){
            top--;

        }else {
            cout<<"stack underflow"<<endl;
        }
    }

    void show_top(){
        if(top>=0){
        cout<<"Top element: "<<arr[top]<<endl;
        }
        else{
            cout<<"Stack is empty.";
        }
    }

    bool empty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    void print_stack(){
        if(top==-1){
            cout<<"stack is empty.."<<endl;
            return;
        }else{
            // [ LIFO ] last in fist out
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){

    Stack s(5);

    s.push(4);
    s.push(3);
    s.push(9);
    s.push(10);

    s.push(20);
   
    s.print_stack();

    s.show_top();
    
    s.print_stack();
    s.show_top();

    if(s.empty()){
        cout<<"stack is empty"<<endl;
    }
    else {
        cout<<"stack isn't empty"<<endl;
    }

    



    return 0;
}