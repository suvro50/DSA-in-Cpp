#include<iostream>
#include<deque>
using namespace std;

int main(){

    // we can push or pop both side in deque
    deque<int> q;

    q.push_back(4);
    q.push_front(5);
    q.push_front(2);
    q.push_back(3);

    for(int i:q) cout<<i<<" ";


    //Also have this operations
    // emplace_front , emplace_back
    // size , erase, clear, begin, end,rbegin, rend, insert, fornt, back

    return 0;
}