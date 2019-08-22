#include<cstdio>
#include<string.h>
#include<queue>
#include<tuple>
using namespace std;

int N, K;
int map[2][1000001];
int visit[2][1000001];
bool flag = true;
int nResult = 1;
void DFS()
{
	// 줄, 칸, 시간
	queue<tuple<int, int, int>>qSearch;
	visit[0][1] = 0;
	qSearch.push(make_tuple(0, 1, 0));

	while (!qSearch.empty())
	{
		int row, col, sec;
		tie(row, col, sec) = qSearch.front();
		qSearch.pop();

		if (col + 1 <= N)
		{
			// 미방문이고
			if (visit[row][col + 1] < 0)
			{
				// 갈 수 있는 칸 이라면
				if (col + 1 > sec + 1 && map[row][col + 1] == 1)
				{
					qSearch.push(make_tuple(row, col + 1, sec + 1));
					visit[row][col + 1] = sec + 1;
				}
			}
		}
		else
		{
			flag = false;
			return;
		}

		if (col + K <= N)
		{
			// 미방문이고
			if (visit[1 - row][col + K] < 0)
			{
				// 갈 수 있는 칸 이라면
				if (col + K > sec + 1 && map[1 - row][col + K] == 1)
				{
					qSearch.push(make_tuple(1 - row, col + K, sec + 1));
					visit[1 - row][col + K] = sec + 1;
				}
			}
		}
		else
		{
			flag = false;
			return;
		}

		if (col - 1 > 0)
		{
			// 미방문이고
			if (visit[row][col - 1] < 0)
			{
				// 갈 수 있는 칸 이라면
				if (col - 1 > sec + 1 && map[row][col - 1] == 1)
				{
					qSearch.push(make_tuple(row, col - 1, sec + 1));
					visit[row][col - 1] = sec + 1;
				}
			}
		}
	}
}
int main(void)
{
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%1d", &map[0][i]);
	for (int i = 1; i <= N; i++)
		scanf("%1d", &map[1][i]);
	memset(visit, -1, sizeof(visit));

	DFS();
	if (flag)
		nResult = 0;
	printf("%d\n", nResult);
	return 0;
}