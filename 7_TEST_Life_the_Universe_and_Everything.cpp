/*
TEST - Life, the Universe, and Everything
#basic #tutorial #ad-hoc-1
Your program is to use the brute-force approach in order to find the Answer to Life, the Universe, and Everything. More precisely... rewrite small numbers from input to output. Stop processing input after reading in the number 42. All numbers at input are integers of one or two digits.


Example
Input:
1
2
88
42
99

Output:
1
2
88
Information
In case of any problems with your code, you can take a look in the forum, you'll find the answer, only for this problem, in various languages.
*/
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n = 0;
	while(true)
	{
		cin>>n;
		if(n == 42)
			break;
		cout<<n<<endl;
	}
	return 0;
}