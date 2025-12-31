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


          //Insert data in middle
        void insert_middle(int pos,int data){
             Node* temp=head;
           
            for(int i=1;i<pos-1;i++){
                temp=temp->next;            
            }

            Node* newnode=new Node(data);

            if(pos==1){   //same as like push_front
                // newnode->next=head;
                // head=newnode;
                push_front(data);
            }

            
        if (temp == nullptr) {
        cout << "Position out of range\n";
        delete newnode;
        return;
        }


            newnode->next=temp->next;
            temp->next=newnode;

            if(newnode->next==nullptr){  //update tail to new newnode
                tail=newnode;
                
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

    l.insert_middle(3,20);
    cout<<endl<<"After insert new data: "<<endl;
    l.print();
    

    return 0;
}
