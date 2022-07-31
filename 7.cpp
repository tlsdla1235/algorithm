#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int n;
int ch[26];
int main()
{

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		int temp = s[i] - 'a';
		ch[temp]++;
	}
	
	int max = 0;
	int temp;
	for (int i = 0; i < 26; i++)
	{
		if (ch[i] > max)
		{
			max = ch[i];
			temp = i;
		}
	}
	char answer = 'a' + temp;
	cout << answer;
	
	return 0;
}
