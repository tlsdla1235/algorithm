#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
string s;
vector<int> v;
int main()
{
	cin >> s;
	int n = s.length();
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'S')
		{
			for (int j = i - 5; j < i + 5 && j<n; j++)
			{
				if (j < 0)
					continue;
				if (s[j] == 'T')
				{
					ans++;
					s[j] = 'O';
					break;
				}
			}
		}
	}
	
	cout << ans;
	return 0;
}
