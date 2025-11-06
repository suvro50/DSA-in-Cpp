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

    Node* head=nullptr;
    Node* tail=nullptr;


    void push_front(int val){   // pust new element in first 
        Node* newnode=new Node(val);

        if(head==nullptr){
            head=tail=newnode;
            return ;
        }else{
            newnode->next=head;
            head=newnode;
        }
    }


    void push_back(int val){    // push new element in last

        Node* newnode=new Node(val);

            if(head==nullptr){
                head=tail=newnode;
                return;

            }else{
                tail->next=newnode;
                tail=newnode;
            }
        }



    void pop_front(){    // pop_front means delete first element in Linked list..
        if(head==nullptr){
            cout<<"no data found..";
            return;
        }

        if(head==tail){  //only one node
        delete head;
        head=tail=nullptr;
        return;
        }
        Node* temp=head;
        head=head->next; 

        delete temp;

        }
        


        void pop_back(){   // pop_front means delete last element in Linked list..
        if(head==nullptr){
        cout<<"No data found";
        return;
        }
        if(head==tail){  //only one node
        delete head;
        head=tail=nullptr;
        return;

        }

        Node* temp=head;

        while(temp->next->next!=nullptr){   //Last node , previout node store tail
        temp=temp->next;
        }

        delete temp->next;
        temp->next=nullptr;
        tail=temp;  // New tail assine in temp
         
    }

    void print(){
    for(Node* i=head;i!=nullptr;i=i->next){
        cout<<i->data<<" ";
        
    }
    
}


int main(){

    
    push_front(3);
    push_front(2);
    push_front(1);

    push_back(5);
    push_back(6);

    print();

    
    cout<<endl<<"After delete 1st node: "<<endl;
    pop_front();
    print();

    pop_back();
    cout<<endl<<"After delete last node: "<<endl;
    print();


    return 0;
}
