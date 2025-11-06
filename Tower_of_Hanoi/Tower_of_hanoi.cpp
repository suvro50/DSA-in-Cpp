#include<iostream>
using namespace std;

void hanoi(int n, char source, char helper, char destination)
{
    if(n==1){

      cout << source << " -> " << destination<<endl;
     return;

    }
   
    hanoi(n-1, source, destination, helper);
    cout << source << " -> " << destination<<endl;
    hanoi(n-1, helper, source, destination);
}


int main() {

    hanoi(3, 'A', 'B', 'C');

    return 0;
}