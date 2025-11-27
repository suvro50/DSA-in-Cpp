#include<iostream>
#include<cmath>
using namespace std;

// must repeat template <typename T> for every function.

template <typename T>

T maxnum(T a,T b){

    return (a>b)? a:b;
}

template<typename T>
T sum(T a, T b){
    return a+b;
}

template<typename T>
T power(T a, T b){
    return pow(a,b);
}


int main(){
    cout<<maxnum<float> (4.2,3.8)<<endl;

    cout<<maxnum<char>('A','G')<<endl;

    cout<<"Sum: "<<sum<int> (2,3)<<endl;

    cout<<"2 to the power 3 is: "<<power<int> (2,3)<<endl;
    
    
    return 0;
}