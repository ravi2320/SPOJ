/*
PRIME1 - Prime Generator
#number-theory
Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
Warning: large Input/Output data, be careful with certain languages (though most should be OK if the algorithm is well designed)
Information
After cluster change, please consider PRINT as a more challenging problem.
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<bool> isPrime(1000000000, false);
	
	for(int i=3; i<1000000000; i += 2)
	{
		isPrime[i] = true;
	}
	
	isPrime[2] = true;
	
	for(long long int i=3; i*i<1000000000; i++)
	{
		if(isPrime[i])
		{
			for(long long int j=i*i; j<1000000000; j += 2*i)
			{
				isPrime[j] = false;
			}
		}
	}
	
	int t;
	cin>>t;
	
	while(t--)
	{
		long long int m, n;
		cin >> m >> n;
		
		for(long long int i=m; i<=n; i++)
		{
			if(isPrime[i])
				cout << i << endl;
		}
		cout<<endl;
	}
	return 0;
}