#include<iostream>
#include<list>
using namespace std;

int main(){
    //push_back = "I made a cake at home, now bring it to the party." 

    // emplace_back = "Make the cake directly at the party." 

    //emplace_back direct create object..  //   *More efficient and fast
    // push_back need pointer for create object 

    list<int> l;
    //This list is Dubly linked list

    l.emplace_back(5);
    l.push_front(3);
    l.push_back(10);
    l.emplace_front(2);

    l.pop_back();
    l.pop_front();

    for(int i:l) cout<<i<<" ";
    return 0;

    //Also have this operations
    // emplace_front , emplace_back
    // size , erase, clear, begin, end,rbegin, rend, insert, fornt, back
}