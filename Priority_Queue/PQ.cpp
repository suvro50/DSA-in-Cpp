#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

    // greater<int> : min values on top 
    // less<int> : max values on top
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5);
    pq.push(2);
    pq.push(8);

    cout << pq.top() << endl; // 2 → smallest element comes first

    return 0;
}
