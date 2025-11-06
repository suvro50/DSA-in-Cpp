#include<iostream>
using namespace std;

bool ispalindrome(string str, int start , int end){
    if(start>=end){
        return true;
    }
    if(str[start]!=str[end]){
        return false;
    }
    return ispalindrome(str,start+1,end-1);
}

int main(){

    string str;
    cout << "Enter a string: ";
    cin >> str;

    bool result=ispalindrome(str,0,str.length()-1);

    if(result){
    cout << str << " is a palindrome." << endl;
    
    }else{
    cout << str << " is not a palindrome." << endl;

    }
    return 0;
}