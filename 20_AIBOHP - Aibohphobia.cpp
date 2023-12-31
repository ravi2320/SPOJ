/*
AIBOHP - Aibohphobia
#dynamic-programming
BuggyD suffers from AIBOHPHOBIA - the fear of Palindromes. A palindrome is a string that reads the same forward and backward.

To cure him of this fatal disease, doctors from all over the world discussed his fear and decided to expose him to large number of palindromes. To do this, they decided to play a game with BuggyD. The rules of the game are as follows:

BuggyD has to supply a string S. The doctors have to add or insert characters to the string to make it a palindrome. Characters can be inserted anywhere in the string.

The doctors took this game very lightly and just appended the reverse of S to the end of S, thus making it a palindrome. For example, if S = "fft", the doctors change the string to "ffttff".

Nowadays, BuggyD is cured of the disease (having been exposed to a large number of palindromes), but he still wants to continue the game by his rules. He now asks the doctors to insert the minimum number of characters needed to make S a palindrome. Help the doctors accomplish this task.

For instance, if S = "fft", the doctors should change the string to "tfft", adding only 1 character.

Input
The first line of the input contains an integer t, the number of test cases. t test cases follow.

Each test case consists of one line, the string S. The length of S will be no more than 6100 characters, and S will contain no whitespace characters.

Output
For each test case output one line containing a single integer denoting the minimum number of characters that must be inserted into S to make it a palindrome.

Example
Input:
1
fft

Output:
1
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int size = s.size();
		vector<vector<int>> dp(size, vector<int>(size, 0));
		
		for(int len = 2; len<=size; len++)
		{
			for(int start = 0; start <= size - len; start++){
				int end = start + len - 1;
				
				if(s[start] == s[end])
				{
					if(len == 2) 
						dp[start][end] = 0;
					else
						dp[start][end] = dp[start + 1][end - 1];
				}
				else
				{
					if(len == 2)
						dp[start][end] = 1;
					else
						dp[start][end] = 1 + min(dp[start][end-1], dp[start+1][end]);
				}
				//cout<<"length : "<<len<<" ["<<start<<"]["<<end<<"]"<<"="<<dp[start][end]<<endl;
			}
		}
		cout << dp[0][size - 1] << endl;
	}
	return 0;
}