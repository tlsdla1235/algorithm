#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int arr[1001];
int n;

int getparent(int arr[], int a)
{
	if (arr[a] == a) return a;
	else
		return arr[a] = getparent(arr, arr[a]);
}
void unionparent(int a, int b)
{
	a = getparent(arr, a);
	b = getparent(arr, b);
	if (a < b)
		arr[b] = a;
	else
		arr[a] = b;
}

bool findparent(int a, int b)
{
	if (getparent(arr, a) == getparent(arr, b))
		return true;
	else
		return false;
}

int main()
{
	cin >> n;
	vector<pair<int, int>>god;

	for (int i = 0;i < n;i++)
	{
		int a, b;
		cin >> a >> b;
		god.push_back(pair<int, int>(a, b));
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
	vector < pair<double, pair<int, int>>>edge;
	for (int i = 0; i < god.size();i++)
	{
		for (int j = i + 1; j < god.size();j++)
		{
			double x = god[i].first;
			double y = god[i].second;
			double xx = god[j].first;
			double yy = god[j].second;
			double distance = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
			edge.push_back(pair<double, pair<int, int>>(distance, pair<int, int>(i, j)));
		}
	}
	sort(edge.begin(), edge.end());
	double sum = 0;
	for (int i = 0; i < edge.size();i++)
	{
		if (findparent(edge[i].second.first, edge[i].second.second))
			continue;
		else
		{
			sum += edge[i].first;
			unionparent(edge[i].second.first, edge[i].second.second);
		}
	}
	printf("%.2f", sum);

	return 0;
}
