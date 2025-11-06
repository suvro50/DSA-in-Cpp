#include <iostream>
using namespace std;

int Count_digit(int n) {
    if (n == 0) return 0;
    int ans=Count_digit(n / 10);
    return 1+ans; 
}
 
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n == 0) {
        cout << "Number of digits in " << n << " = 1" << endl;
    } else {
        cout << "Number of digits in " << n << " = " << Count_digit(n) << endl;
    }
    return 0;
}