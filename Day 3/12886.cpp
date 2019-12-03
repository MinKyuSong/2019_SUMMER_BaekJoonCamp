#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int N, A, B, C, t;
int map[1501][1501];
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void DFS()
{
	queue<pair<int, int>> qSearch;
	qSearch.push(make_pair(A, B));
	qSearch.push(make_pair(B, C));
	qSearch.push(make_pair(A, C));

	while (!qSearch.empty())
	{
		int x, y, z;
		x = qSearch.front().first;
		y = qSearch.front().second;
		z = N - (x + y);
		qSearch.pop();
		if (x > y)
			swap(x, y);
		if (y > z)
			swap(y, z);
		if (x > y)
			swap(x, y);

		map[x][y] = 1; map[x][z] = 1; map[y][z] = 1;
		if (x != y)
		{
			if (x + x > y - x)
			{
				if (map[y - x][x + x] == 0)
					qSearch.push(make_pair(y - x, x + x));
			}
			else
			{
				if (map[x + x][y - x] == 0)
					qSearch.push(make_pair(x + x, y - x));
			}
		}
		if (x != z)
		{
			if (x + x > z - x)
			{
				if (map[z - x][x + x] == 0)
					qSearch.push(make_pair(z - x, x + x));
			}
			else
			{
				if (map[x + x][z - x] == 0)
					qSearch.push(make_pair(x + x, z - x));
			}
		}
		if (y != z)
		{
			if (y + y > z - y)
			{
				if (map[z - y][y + y] == 0)
					qSearch.push(make_pair(z - y, y + y));
			}
			else
			{
				if (map[y + y][z - y] == 0)
					qSearch.push(make_pair(y + y, z - y));
			}
		}
	}
}
int main(void)
{
	cin >> A >> B >> C;
	N = A + B + C;
	if (N % 3 != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	t = N / 3;

	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			map[i][j] = 0;
	DFS();
	cout << map[t][t] << endl;
	return 0;
}