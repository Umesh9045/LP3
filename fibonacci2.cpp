#include <iostream>
using namespace std;

int main() {
    int num1 = 0, num2 = 1;
    int sum = 0, n;

    cout << "Enter the number:\n";
    cin >> n;

    if (n == 1) {
        cout << num1;
    }
    else if (n == 2) {
        cout << num2;
    }
    else if (n >= 3) {

        for (int i = 3; i <= n; i++) {
            sum = num1 + num2; // Calculate the sum of the last two Fibonacci numbers
            num1 = num2;       // Update num1 to the previous num2
            num2 = sum;        // Update num2 to the sum
        }

        cout << num2; // Print the nth Fibonacci number
    }

    return 0;
}
