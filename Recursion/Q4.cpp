#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n == 0) return 0;
    int lastdigit=n%10;
    
    int ans=sumOfDigits(n / 10);
    return lastdigit+ans; 
}
 
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum of digits of " << n << " = " << sumOfDigits(n) << endl;

    return 0;
}
