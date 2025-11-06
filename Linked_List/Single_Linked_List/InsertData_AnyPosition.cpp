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



    void push_front(int val){     // pust new element in first 
        Node* N=new Node(val);

        if(head==nullptr){
            head=tail=N;
            return;

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


          //Insert data in middle
        void insert_middle(int pos,int data){
            Node* newnode=new Node(data);

            if(pos==1){
                newnode->next=head;
                head=newnode;
            }

            
        if (newnode == nullptr) {
         cout << "Position out of range\n";
         delete newnode;
         return;
        }

        Node* temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }

            newnode->next=temp->next;
            temp->next=newnode;

            if(temp->next==nullptr){  //update tail to new newnode
                tail=newnode;
                
            }

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

    insert_middle(6,20);
    cout<<endl<<"After insert new data: "<<endl;
    print();


    return 0;
}
 