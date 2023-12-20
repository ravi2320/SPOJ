/*
NITK06 - MODIFY SEQUENCE
#ad-hoc-1
Suppose we have a sequence of non-negative integers, Namely a1, a2, ..., an. At each time we can choose one term ai with 0 < i < n and we subtract 1 from both ai and ai+1. We wonder whether we can get a sequence of all zeros after several operations.

Input
The first line is the number of test cases T (0 < T <= 20).

The first line of each test case is a number N (0 < N <= 10000). The next line is N non-negative integers, 0 <= ai <= 109.

Output
If it can be modified into all zeros with several operations output “YES” in a single line, otherwise output “NO” instead.

Example
Input:
2
2
1 2
2
2 2

Output:
NO
YES
Explanation
It is clear that [1 2] can be reduced to [0 1] but no further to convert all integers to 0. Hence, the output is NO.

In second case, output is YES as [2 2] can be reduced to [1 1] and then to [0 0] in just two steps.



#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		for(int i=0; i<n-1; i++)
		{
			arr[i+1] -= arr[i];
		}
		if(arr[n-1]==0) 
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
*/

//Optimal Solution
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		int ans = 0, x;
		for(int i=0; i<n; i++)
		{
			cin>>x;
			ans = x - ans;
		}
		if(ans==0) 
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}