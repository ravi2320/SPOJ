/*
PLAYGAME - PLAYGAME
no tags 
Hemlata and Ritu were playing a game from a number of coins. Hemlata was jealous of Ritu. She wanted to win at all cost. A stack consists of n coins. Any player can take either 1, 2 or 5 (anyone number of coins) coins from stack at a time. Both Hemlata and Ritu play their moves alternatively.

Hemlata always starts first. Both play optimally. Your job is to predict the output beforehand. A player who can't take any coin loses the game. A player can take only one of 1, 2, 5 number of coins at a time in a move.

Input
First line contains number of testcases t. 0 < t <= 10^5

An integer n denoting number of coins. 0 <= n <= 10^18

Output
For each testcase printf "Hemlata" if Hemlata wins, else print "Ritu" if Ritu wins (without quotes) in different lines .

Example
Input:
3
1
2
3
Output:
Hemlata
Hemlata
Ritu
*/
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long int t;
	cin >> t;
	
	while(t--)
	{
		long long int n;
		cin >> n;
		
		if( n % 3 == 0)
		{
			cout<<"Ritu"<<endl;
		}
		else
		{
			cout<<"Hemlata"<<endl;
		}
	}
	return 0;
}