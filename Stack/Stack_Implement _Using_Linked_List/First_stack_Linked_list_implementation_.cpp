#include<iostream>
#include<stack>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next=nullptr;
    }
};
 Node* top;

struct Stack{
   
    Stack(){
        top=nullptr;
    }
    
    //destructor
    ~Stack(){
        while(top!=nullptr){
            pop();
        }
    }

    void push(int val){
        Node* newnode=new Node(val);
        if(top==nullptr){
           top=newnode;
           return;
        }else{
            newnode->next=top;
            top=newnode;
        }
    }

    void pop(){
        if(top==nullptr){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
    }

    bool empty(){

        return (top==nullptr);
    }

    void show_top(){
        if(top==nullptr){
            cout<<"Stack is empty"<<endl;
        }else{
            cout<<"Top is: "<<top->data<<endl;
        }
    }


    void print(){
        for(Node* i=top;i!=nullptr;i=i->next){
            cout<<i->data<<" ";
        }
    }

    void Stack_size(){
        int count=0;
        for(Node* i=top;i!=nullptr;i=i->next){
            count++;
        }
        cout<<endl<<"Size of the stack is: "<<count<<endl;
    }

};

int main(){

    Stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(9);
    s.push(10);

    s.print();
     s.Stack_size();
     s.show_top();
   
    s.pop();
    s.pop();
    
    cout<<endl;
    s.print();

    s.Stack_size();
    cout<<endl;

    s.show_top();


    if(s.empty()) {
    cout<<"Stack is empty"<<endl;
    }
    else {
    cout<<"Stack isn't empty"<<endl;
    }

    return 0;
}