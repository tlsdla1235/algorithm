#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int n;
int d[101];
int fib(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (d[n] != 0) return d[n];
	else return d[n] = fib(n - 1) + fib(n - 2);
}
int main()
{
	cin >> n;
	cout << fib(n);
	return 0;
}
