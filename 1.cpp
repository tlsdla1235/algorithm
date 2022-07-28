#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int n;
vector<int> v;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int sum = 1;
	for (int i = 0; i < n; i++)
	{
		if (sum < v[i])
			break;
		sum += v[i];
	}
	cout << sum;
	return 0;
}
