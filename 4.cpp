#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int n, m;
vector<int> a[1001];
bool visit[1001];
queue<int> q;
vector<pair<int, int>> result;
void bfs(int start)
{
	int count = 0;
	q.push(start);
	visit[start] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if (!visit[y]) {
				visit[y] = true;
				q.push(y);
				count++;
			}
		}
	}
	result.push_back(make_pair(-1*count, start));
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int c, d;
		cin >> c >> d;
		a[c].push_back(d);
		a[d].push_back(c);
	}
	for (int i = 1; i <= n;i++)
	{
		if (visit[i] == false)
		{
			bfs(i);
		}
	}
	sort(result.begin(), result.end());
	cout << result[0].second;
	return 0;
}
