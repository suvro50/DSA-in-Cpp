#include<iostream>
#include<string>
using namespace std;

int main(){
    // count last word length 
    
    string str;
    cout<<"Enter a stirng:";
    getline(cin,str);  // must given for taking string input

    bool found=false;
    int count=0;
   
    for(int i = str.length() - 1; i >= 0; i--) {

        if(str[i] != ' ') { // it start count only , when space not avalable
            found = true;
            count++;
        }
        else if(found) {
            break;  // last word finished
        }
    }

    cout << count;
    return 0;
}