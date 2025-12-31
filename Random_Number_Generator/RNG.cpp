#include<bits/stdc++.h>
//#include<stdlib.h> // random number generator hader file
using namespace std;

int main(){
    // int randnum= rand();  // print any random number

    // cout<<"Randmnumber: "<<randnum<<endl;

    // int randnum=rand() % 5;  // print random number from 0 - 4
   // int randnum1=rand()%10   //  print random number from 0 - 9

    for(int i=0;i<10;i++){  // generat 10 random number , must be declear under the loop
     //int randnum=rand() % 5;  // start from 0;
      int randnum1= 1+ rand() % 5; // start from 1 to 4
        cout<<randnum1<<" ";
    }


    return 0;
}