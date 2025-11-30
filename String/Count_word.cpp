#include<iostream>
#include<string>
using namespace std;

int main(){
    // count the number of word 
    
    string str1;
    cout<<"Enter a stirng:";
    getline(cin,str1);  // must given for taking string input

    bool found=false;
    int c=0;

    for(int i=0;i<str1.length();i++){
        if(str1[i]!=' ' && !found){
            found=true;
            c++;

        }else if (str1[i]==' '){
            found=false;
        }
    }
    cout<<c;
    return 0;
}