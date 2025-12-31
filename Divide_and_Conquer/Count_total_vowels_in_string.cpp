#include<iostream>
#include<string>
using namespace std;

int count_vowels(string str,int start,int end){
    

    if(start==end){
        char c=tolower(str[start]);
        
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        return 1;
    }else return 0;
}

    int mid=start+ (end-start)/2;

    int left=count_vowels(str,start,mid);
    int right=count_vowels(str,mid+1,end);

    return left+right;
}

int main(){

    string str="HEllo Suvro";

    int n=str.length();

    int ans=count_vowels(str,0,n-1);

    cout<<ans;


    return 0;
}