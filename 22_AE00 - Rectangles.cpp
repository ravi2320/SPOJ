/*
AE00 - Rectangles
#ad-hoc-1
Byteman has a collection of N squares with side 1. How many different rectangles can he form using these squares?

Two rectangles are considered different if none of them can be rotated and moved to obtain the second one. During rectangle construction, Byteman can neither deform the squares nor put any squares upon any other ones.

Input
The first and only line of the standard input contains one integer N (1 <= N <= 10000).

Output
The first and only line of the standard output should contain a single integer equal to the number of different rectangles that Byteman can form using his squares.

Example
For the input data:

6
the correct result is:

8
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	int ans = n;
	for(int i=2; i<=n/2; i++){
		for(int j=i; j<= n/2; j++){
			if(i*j <= n)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	int ans = n;
	for(int i=2; i<=n; i++){
		for(int j=2; j<= floor(sqrt(i)); j++){
			if(i%j == 0)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}