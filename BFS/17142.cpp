#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
vector<pair<int, int>> vVir;
int map[50][50];
int mapOriginal[50][50];
int mapCopy[50][50];
int visit[50][50];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

int N, M;
bool flag = true;
int nResult = 3000;

bool valid(int y, int x)
{
	return (y >= 0 && y < N && x >= 0 && x < N);
}

void clone()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			mapCopy[i][j] = mapOriginal[i][j];
}

void spread(int idx, int cnt)
{
	// 범위 넘어가면 그만둔다.
	if (idx >= vVir.size())
		return;
	// 다 찝으면 BFS
	if (cnt == M)
	{
		clone();
		queue<pair<int, int>> qSearch;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				visit[i][j] = -1;
				if (mapCopy[i][j] > 1)
				{
					visit[i][j] = 0;
					qSearch.push(make_pair(i, j));
				}
			}
		while (!qSearch.empty())
		{
			int y, x;
			y = qSearch.front().first;
			x = qSearch.front().second;
			qSearch.pop();
			if (mapCopy[y][x] == 2) continue;
			for (int i = 0; i < 4; i++)
			{
				if (valid(y + dy[i], x + dx[i]))
				{
					if (mapCopy[y + dy[i]][x + dx[i]] != 1 && visit[y + dy[i]][x + dx[i]] < 0)
					{
						visit[y + dy[i]][x + dx[i]] = visit[y][x] + 1;
						qSearch.push(make_pair(y + dy[i], x + dx[i]));
					}
				}
			}
		}
		bool check = true;
		int nTemp = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j] < 0 && mapCopy[i][j] == 0)
					check = false;
				if (visit[i][j] > nTemp)
					nTemp = visit[i][j];
			}
		if (check && nTemp < nResult)
		{
			nResult = nTemp;
			flag = false;
		}
	}
	else
	{
		// 그냥 넘어가기
		spread(idx + 1, cnt);
		// 활성화하기
		mapOriginal[vVir[idx].first][vVir[idx].second]++;
		spread(idx + 1, cnt + 1);
		mapOriginal[vVir[idx].first][vVir[idx].second]--;
	}
	return;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			mapOriginal[i][j]=map[i][j];
			if (mapOriginal[i][j] == 2)
			{
				vVir.push_back(make_pair(i, j));
			}
		}

	spread(0, 0);
	if (flag)
		nResult = -1;
	cout << nResult << endl;
	return 0;
}