#include<iostream>
using namespace std;
struct student{

    string name;
    int roll;
    int mark;

    student() {} // default constructor required

    student (string name,int roll,int mark){
        this->name=name;
        this->roll=roll;
        this->mark=mark;
    }

    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll: "<<roll<<endl;
        cout<<"Mark: "<<mark<<endl;
    }

};


void swapd(student &a,student &b){
    student temp=a;
    a=b;
    b=temp;
}

void Bubble_sort(student s[],int n){

    for(int i=0;i<n-1;i++){
        bool swp=false;
        for(int j=0;j<n-i-1;j++){
            if(s[j].mark<s[j+1].mark){
            swapd(s[j],s[j+1]);
            swp=true;
            }
        }
        if(!swp) break;
    }

}


int Binary_search(student s[],int n,int key){
    int start=0;
    int end=n-1;


    //Must for use Birary search : Array must be sorted in Asending or Decending order..
    while(start>=end){
        int mid=start+(end-start)/2;
        
        if(s[mid].mark==key){
            return mid;
        }
        if(s[mid].mark<key){
            start=mid+1;
        }else {
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    string name;
    int roll,mark;
    cout<<"Enter number of student: ";
    cin>>n;

    student s[n];  

    for( int i=0;i<n;i++){
        cout<<"Enter info for student: "<<i+1<<endl;

        cout<<"Enter name: ";
        cin>>name;

        cout<<"Enter Roll: ";
        cin>>roll;

        cout<<"Enter mark: ";
        cin>>mark;
        
        s[i]=student(name,roll,mark);
    }

    
    int key;
    cout<<"Enter key: ";
    cin>>key;

    cout << "\nAll student info:\n";

     for(int i=0;i<n;i++){
       s[i].print();
       cout<<endl;

     }
    
     
     Bubble_sort(s,n);

     cout<<"After sorting Asending  of mark: "<<endl;
     for(int i=0;i<n;i++){
       s[i].print();
       cout<<endl;

     }
      
     int searching_result=Binary_search(s,n,key);

     if(searching_result==-1){
        cout<<"No student found with mark "<<key;
     }else{
        cout<<"Student found who get "<<key<<" mark"<<endl;
        
       int i=searching_result;
       while(i>=0 && s[i].mark==key) {
        i--;
       }
        i++;

       
        while( i < n && s[i].mark == key){
            s[i].print();
            cout << endl;
            i++;
        }
     }
    return 0;
}