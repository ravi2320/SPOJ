/*
FCTRL2 - Small factorials
#math #big-numbers
You are asked to calculate factorials of some small positive integers.

Input
An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.

Output
For each integer n given at input, display a line with the value of n!

Example
Sample input:
4
1
2
5
3
Sample output:

1
2
120
6
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> factorial(105, 0);

int factorial_fun(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (factorial[n] != 0) {
        return factorial[n];
    }
    // Recursive case: n! = n * (n-1)!
    return (n * factorial_fun(n - 1));
}

int main() {
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i <= 100; i++) {
        factorial[i] = factorial_fun(i);
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << factorial[n] << endl;
    }
    return 0;
}
