#include<iostream>
using namespace std;
// for passing int & float same time we use multi_parameter 
 // Works (int + double)  ,  ✅ Works (char + int)
template<typename T1, typename T2,typename T3>

T3 findmax(T1 a, T2 b, T3 c) {
    if(a >= b && a >= c) {  // Use >= to handle equal numbers
        return a;
    } 
    else if(b >= a && b >= c) {
        return b;
    } 
    else {
        return c;
    }
}
// **VVI
// One template declaration applies to ONLY one class or ONE function.

int main(){

    cout<<"Max: "<<findmax(5.5,2,9.9)<<endl;
    
    cout<<"Max: "<<findmax(5.5,20,9.9)<<endl;

    return 0;
}