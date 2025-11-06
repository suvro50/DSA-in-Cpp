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


        void detele_Any_position(int pos){
              Node* temp=head;
            //delete first node 
            if(pos==1){
                head=head->next;
                delete temp;
            }
            else{

                for(int i=1;i<pos-1;i++){
                    temp=temp->next;
                }
                if(temp->next==nullptr){
                    cout<<"Your position point to the null";
                }

                Node* deletenode=temp->next;  //store node for delete;
                temp->next=temp->next->next;  //updata temp to deletenode next value

                delete deletenode;
                
            }

        } //1,2,3,4,5

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

    cout<<endl<<"After delete: "<<endl;
    detele_Any_position(2);
    print();



    return 0;
}
