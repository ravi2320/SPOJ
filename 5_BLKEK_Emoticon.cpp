/*
BLKEK - Emoticon
#dynamic-programming #adhoc
When internet become popular, instant messaging is used by many people. Legend says that chat used to not be able to send image or stickers. So, users that want to express themself with more than word will have to use something called "smiley" or "emoticon" (it's called emoji now). Example of emoticons are :), :(, :v, XD, and :p.

Some people don't like that kind of emote because they have to be rotated, so they used something like  ^_^, T_T, x_x, and >=< (it's a giant enemy crab). Creativity rises as times passed, and emoticon starts using weird symbol that's not on a typical keyboard like ( ≧Д≦), (ノಠ益ಠ)ノ彡┻━┻, ( ͡° ͜ʖ ͡°), щ(ﾟдﾟщ), and (っ˘ڡ˘)っ─∈. With hard to type emotes, some chatting site use word replace to change word into picture. For example, if someone types "Kappa" the site will change it to Kappa.

Henrik plans to create a chatting site that changes "KEK" to LUL. To increase that emote's appearance, Henrik will change every message containing the subsequence "KEK". For example, if someone types "BUKAHEHELAPAK" it will be changed because the subsequence "KEK" exists in that message. Henrik wants to know how many ways he can take the subsequence "KEK" in a message. For example, in  "BUKAHEHELAPAK" there are 2 ways to get the subsequence "KEK", using the bold letters in "BUKAHEHELAPAK" and "BUKAHEHELAPAK".

Input
First line is N, number of messages that need to be processed (N ≤ 1000). Next N line each contains a string containing the letter A-Z not more than 2000 letters in length.

Output
For each message, output the number of way subsequence "KEK" can be obtained.

Example
Input:
3
BUKAHEHELAPAK
KEKEK
KKE

Output:
2
4
0 

Brute Force Approach
--------------------
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		
		int l = s.size();
		int cnt = 0;
		for(int i=0; i<l; i++)
		{
			if(s[i] == 'K')
			{
				for(int j=i+1; j<l; j++)
				{
					if(s[j]=='E')
					{
						for(int k=j+1; k<l; k++)
						{
							if(s[k] == 'K')
							{
								cnt++;
							}
						}
					}
				}
			}
		}
		
		cout<<cnt<<endl;
	}
	return 0;
}
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		
		int l = s.size();
		vector<int> front(l, 0);
		vector<int> back(l, 0);
		
		front[0] = (s[0] == 'K' ? 1:0);
		back[l-1] = (s[l-1] == 'K' ? 1:0);
		
		for(int i=1; i<l; i++)
		{
			front[i] = front[i-1] + (s[i] == 'K' ? 1:0);
		}
		
		for(int j=l-2; j>=0; j--)
		{
			back[j] = back[j+1] + (s[j] == 'K' ? 1:0);
		}
		
		int answer = 0;
		for(int i=1; i<l; i++)
		{
			if(s[i]=='E')
			answer += front[i] * back[i];
		}
		
		cout<<answer<<endl;
	}
	return 0;
}