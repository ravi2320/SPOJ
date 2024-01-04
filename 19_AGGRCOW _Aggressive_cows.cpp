/*
AGGRCOW - Aggressive cows
#binary-search
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int placeCows(vector<long long int> &x, long long int min_dist)
{
	long long int total_place_cows = 1;
	long long int last_placed = 0;
	
	for(int i=1; i<x.size(); i++)
	{
		long long int distance = x[i] - x[last_placed];
		if(distance >= min_dist)
		{
			last_placed = i;
			total_place_cows++;
		}
	}
	return total_place_cows;
}

long long int solve(vector<long long int> &x, long long int c)
{
    long long int low = 0;
    long long int high = 1000000001;
    long long int ans = 0;

    while (low <= high)
    {
        long long int mid = (low + high) / 2;
        long long int total_place_cows = placeCows(x, mid);

        if (total_place_cows < c)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}


int main() {
	// your code goes here
	int t, n, c;
	cin >> t;
	while(t--)
	{
		cin >> n >> c;
		vector<long long int> x;
		for(int i=0; i<n; i++)
		{
			int temp;
			cin>>temp;
			x.push_back(temp);
		}
		sort(x.begin(), x.end());
		cout << solve(x, c) << endl;
	}
	return 0;
}