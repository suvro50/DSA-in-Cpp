#include<iostream>
using namespace std;

// Print 1 to n
void increasing(int n){
    if(n==0) return;

    increasing(n-1);
     cout<<n<<endl;
}
    

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    increasing(n);

    return 0;
}