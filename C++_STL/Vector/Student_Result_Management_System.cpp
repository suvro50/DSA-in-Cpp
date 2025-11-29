#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class student{
    public:
    string name;
    int id;
    double cgpa;
    student(string name,int id, double cgpa){
        this->name=name;
        this->id=id;
        this->cgpa=cgpa;
    }
   void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"Cgpa: "<<cgpa<<endl;
    }
};

 void Add_student(vector<student> &s){
     int n;
    cout<<"Enter how many student info you want to add: ";
    cin>>n;
    
    for(int i=0;i<n;i++){
        string name;
        int id;
        double cgpa;

        cout<<endl;
        cout<<"Enter info for student no "<<i+1<<endl;

        cout<<"Enter name: ";
        cin>>name;
        
        cout<<"Enter id: ";
        cin>>id;

        cout<<"Enter cgpa: ";
        cin>>cgpa;
        s.emplace_back(name,id,cgpa);
    }
 }

 bool sort_cgpa(student& s1,student& s2){
    return s1.cgpa>s2.cgpa;
 }


 void search_by_id(vector<student>& s){
    int id;
    cout<<"Enter you search id: ";
    cin>>id;
    bool found=false;

    for(int i=0;i<s.size();i++){
        if(s[i].id==id){
            cout<<"Id found"<<endl;
            s[i].print();
            found=true;
            break;
        }
    }

    if(!found){
        cout<<"No student found with this id"<<endl;
    }
 }

 void delete_student_by_id(vector<student>& s){
    int id;
    cout<<"Enter id you want to delete: ";
    cin>>id;
    bool found=false;
    for(auto i=s.begin();i!=s.end();i++){
        if(i->id==id){
            s.erase(i);
            found=true;
            break;
        }
    }
    if(!found){
        cout<<"Id not found for delete"<<endl;
    }

 }

 void Update_student_CGPA_by_ID(vector<student>& s){

    int id;
    cout<<"Enter student id , you want to update cgpa: ";
    cin>>id;

    bool found=false;

    for(auto i=s.begin();i!=s.end();i++){
        double cgpa;
        if(i->id==id){
            cout<<"Enter new cgpa for id no "<<id<<": ";
            cin>>cgpa;
            i->cgpa=cgpa;
            found=true;
            break;
        }
    }
    if(!found){
        cout<<"Id not found"<<endl;
    }



 }

int main(){

    vector<student> s;

    int n;
    do{
        cout<<"1.Add student"<<endl;
        cout<<"2.Sort student by cgpa"<<endl;
        cout<<"3.Search student by thair id"<<endl;
        cout<<"4.Delete student by thair id"<<endl;
        cout<<"5.Update student cgpa"<<endl;
        cout<<"6.Show student info"<<endl;
        cout<<"7.Exit"<<endl;

        cout<<"Enter any option: ";
        cin>>n;

        switch(n){
            case 1:Add_student(s); break;
            case 2:sort(s.begin(),s.end(),sort_cgpa); break;
            case 3:search_by_id(s); break;
            case 4:delete_student_by_id(s); break;
            case 5:Update_student_CGPA_by_ID(s); break;
            case 6:{
                 int c=1;
               for(auto i:s){
                cout<<endl;
                cout<<"Student info "<<c++<<": "<<endl;
                i.print();
               } 
               break;
            }
            case 7:"Exiting.."; break;
        }
    }while(n!=7);
    
    // Add_student(s);
    // sort(s.begin(),s.end(),sort_cgpa);

    // int c=1;
    // for(auto i:s){
    //     cout<<endl;
    //     cout<<"Student info "<<c++<<": "<<endl;
    //     i.print();
    // }

    // search_by_id(s);
    // delete_student_by_id(s);

    // c=1;  // reset count

    // cout<<"After delete: "<<endl;
    // for(auto i:s){
    //     cout<<endl;
    //     cout<<"Student info "<<c++<<": "<<endl;
    //     i.print();
    // }
    // Update_student_CGPA_by_ID(s);
    //  c=1;  // reset count
    // cout<<"After update cgpa: "<<endl;
    // for(auto i:s){
    //     cout<<endl;
    //     cout<<"Student info "<<c++<<": "<<endl;
    //     i.print();
    // }

    return 0;
}