/*
LASTDIG - The last digit
#number-theory #ad-hoc-1
Nestor was doing the work of his math class about three days but he is tired of make operations a lot and he should deliver his task tomorrow. His math’s teacher gives him two numbers a and b. The problem consist of finding the last digit of the potency of base a and index b. Help Nestor with his problem. You are given two integer numbers: the base a (0 <= a <= 20) and the index b (0 <= b <= 2,147,483,000), a and b both are not 0. You have to find the last digit of ab.

Input
The first line of input contains an integer t, the number of test cases (t <= 30). t test cases follow. For each test case will appear a and b separated by space.

Output
For each test case output an integer per line representing the result.

Example
Input:
2
3 10
6 2

Output:
9
6
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> table(9, vector<int>(4, 0));

int LastDigit(long long int a, long long int b)
{
	if(a==0) return 0;
	if(b==0) return 1;
	a = a%10;
	
	if(b%4 == 0)
		return table[a-1][3];
	else
		return table[a-1][(b % 4)-1];
}
int main() {
	
	for(int i=1; i<=9; i++)
	{
		table[i-1][0] = i;
		for(int j=1; j<4; j++)
		{
			table[i-1][j] = (i * table[i-1][j-1])%10;
		}
	}
	
	int t;
	cin >> t;
	
	while(t--)
	{
		long long int a, b;
		cin >> a >> b;
		
		cout << LastDigit(a, b) << endl;
	}
	return 0;
}