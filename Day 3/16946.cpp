#include<cstdio>
#include<queue>
#include<set>
using namespace std;

int map[1001][1001];
int group[1001][1001];
static int gCount[100001];
bool gCheck[100001];
int g=1;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int N, M;
queue<pair<int, int>> qSearch;
bool valid(int y, int x)
{
	return (y >= 1 && y <= N && x >= 1 && x <= M);
}
void BFS(int y, int x)
{
	qSearch.push(make_pair(y, x));
    group[y][x]=g++;
    gCount[group[y][x]]++;
	while (!qSearch.empty())
	{
		int y, x;
		y = qSearch.front().first;
		x = qSearch.front().second;
		qSearch.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (valid(ny, nx))
			{
				if (map[ny][nx] == 0 && group[ny][nx]==0)
				{
					qSearch.push(make_pair(ny, nx));
					group[ny][nx] = group[y][x];
                    gCount[group[ny][nx]]++;
				}
			}
		}
	}
	return;
}
int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
        {
            scanf("%1d", &map[i][j]);
            group[i][j]=0;
        }
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
        {
            if(map[i][j]==0 &&group[i][j]==0)
                BFS(i,j);
        }
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
            if(map[i][j]==1)
            {
                set<int> s;
                for (int k = 0; k < 4; k++) {
                    if (!valid(i + dy[k], j + dx[k])) continue;
                    s.emplace(group[i + dy[k]][j + dx[k]]);
                }
                for (int v : s) {
                    map[i][j] += gCount[v];
                }
            }
            printf("%d", map[i][j]%10);
		}
        printf("\n");
	}
	return 0;
}