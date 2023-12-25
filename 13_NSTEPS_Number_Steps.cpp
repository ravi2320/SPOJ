/*
NSTEPS - Number Steps
#ad-hoc-1
Starting from point (0,0) on a plane, we have written all non-negative integers 0, 1, 2, ... as shown in the figure. For example, 1, 2, and 3 has been written at points (1,1), (2,0), and (3, 1) respectively and this pattern has continued.

 

Illustration
 

You are to write a program that reads the coordinates of a point (x, y), and writes the number (if any) that has been written at that point. (x, y) coordinates in the input are in the range 0...10000.

Input
The first line of the input is N, the number of test cases for this problem. In each of the N following lines, there is x, and y representing the coordinates (x, y) of a point.

Output
For each point in the input, write the number written at that point or write No Number if there is none.

Example
Input:
3
4 2
6 6
3 4

Output:
6
12
No Number
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    unordered_map<int, pair<int, int>> moves;
    moves[0] = {1, 1};
    moves[1] = {1, -1};
    moves[2] = {1, 1};  // Corrected value for move 2
    moves[3] = {-1, 1};

    unordered_map<string, int> answer;

    answer["0,0"] = 0;
    int x = 0, y = 0;

    for (int i = 0; i < 10000; i++) {
        int index = i % 4;
        pair<int, int> curr = moves[index];
        x +=  curr.first;
        y += curr.second;

		string str = to_string(x) + "," + to_string(y);
        answer[str] = i + 1;
    }

    /* Corrected iterator usage:
    for (const auto& it : answer) {
        cout << it.first << " " << it.second << "\n";
    }*/

	int n;
	cin>>n;
	while(n--)
	{
		int x, y;
		cin >> x >> y;
		string str = to_string(x) + "," + to_string(y);
		
		if(answer.find(str) == answer.end())
		{
			cout<<"No Number"<<endl;
		}
		else
		{
			cout<<answer[str]<<endl;
		}
	}
	
    return 0;
}
