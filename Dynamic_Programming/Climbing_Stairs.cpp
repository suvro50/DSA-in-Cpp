#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    if (n == 1) return 1;

    vector<int> step(n + 1);

    step[1] = 1;
    step[2] = 2;

    for (int i = 3; i <= n; i++) {
        step[i] = step[i - 1] + step[i - 2];
    }

    return step[n];
}

int main() {
    int n;
    cout<<"Enter number of stapes: ";
    cin >> n;

    cout <<"Total number of stapes need : "<< climbStairs(n) << endl;

    return 0;
}
