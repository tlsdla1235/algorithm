	#include <iostream>
	#include<vector>
	#include<algorithm>
	#include<queue>
	using namespace std;
	int dp[50] = { 1,1, };
	int fib(int n)
	{
		if (n == 0)
		{
			return 1;
		}
		if (n == 1)
		{
			return 1;
		}
		else if (dp[n] != 0)
		{
			return dp[n];
		}
		else
			return dp[n] = fib(n - 1) + fib(n - 2);
	}
	int main()
	{
		fib(49);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (x == 1)
			{
				cout << 1 << '\n';
			}
			else if (x == 0)
			{
				cout << 0 << '\n';
			}


			else {

				cout << dp[x - 1] << '\n';
			}
		}
		return 0;
	}
