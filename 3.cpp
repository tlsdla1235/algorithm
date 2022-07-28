#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int n, m;
char map[101][101];
int fid[101][101];
int dx1[] = { -1,1,0,0 };
int dy1[] = { 0,0,-1,1 };
int dx2[] = { 0,-1,1,-2,2 };
int dy2[] = { 0,-1,1,-2,2 };
int vis[101][101];
int main()
{
	cin >> n >> m;
	vector<int> v;
	for (int i = 0;i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[n][m];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'C')
			{
				fid[i][j] = 1;
				for (int k = 0; k < 4; k++)
				{
					int x = i + dx1[k];
					int y = i + dy1[k];
					if (x >= 0 && x < n && y >= 0 && y < m)
					{
						fid[x][y] = 1;
					}
				}
			}
			else if (map[i][j] == 'L')
			{
				fid[i][j] = 1;
				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						int x = i + dx2[a];
						int y = i + dy2[b];
						if (x >= 0 && x < n && y >= 0 && y < m)
						{
							fid[x][y] = 1;
						}
					}
				}
			}
			else if (map[i][j] == 'T')
			{
				fid[i][j] = 1;
				for (int a = 0; a < 5; a++)
				{
					for (int b = 0; b < 5; b++)
					{
						int x = i + dx2[a];
						int y = i + dy2[b];
						if (x >= 0 && x < n && y >= 0 && y < m)
						{
							fid[x][y] = 1;
						}
					}
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j] == 0 && map[i][j] == 0)
			{
				queue<pair<int,int>> q;
				q.push(make_pair(i,j));
				int count = 1;
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++)
					{
						int xx = x + dx1[i];
						int yy = y + dy1[i];
						if (xx >= 0 && xx < n && yy >= 0 && yy < m && fid[xx][yy] == 0 && vis[xx][yy] == 0)
						{
							count++;
							vis[xx][yy] = 1;
							q.push(make_pair(xx, yy));
						}
					}
				}
				v.push_back(count);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v[v.size() - 1];
	return 0;
}
