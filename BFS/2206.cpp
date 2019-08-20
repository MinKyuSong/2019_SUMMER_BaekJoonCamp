#include <cstdio>
#include <queue>

using namespace std;
typedef struct state
{
    int y, x;
    int count;
    bool crush = false;
} state;
int map[1001][1001];
bool visit[1001][1001][2];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};
bool flag=true;
int nResult;
int N, M;
bool valid(int y, int x)
{
    return (y > 0 && y <= N && x > 0 && x <= M);
}
void DFS()
{
    queue<state> qSearch;
    state start;
    start.y = 1;
    start.x = 1;
    start.count = 1;
    visit[start.y][start.x][0]=true;
    if(N==1&&M==1)
    {
        flag=false;
        nResult=1;
    }
    qSearch.push(start);
    while (!qSearch.empty())
    {
        state now(qSearch.front());
        qSearch.pop();
        for (int i = 0; i < 4; i++)
        {
            // 유효한 지점이고
            if (valid(now.y + dy[i], now.x + dx[i]))
            {
                // 도착지점이면 update
                if (now.y + dy[i] == N && now.x + dx[i] == M)
				{
                    flag=false;
					if (nResult > now.count+1)
						nResult = now.count+1;
				}
                // 벽이고 방문하지 않았으면
                if(map[now.y + dy[i]][now.x + dx[i]]==1&&
                    !visit[now.y + dy[i]][now.x + dx[i]][now.crush])
                {
                    // 이미 부쉈으면 건너뛴다.
                    if(now.crush)
                        continue;
                    
                    // 부수지 않았으면
                    state next;
                    next.y = now.y + dy[i];
                    next.x = now.x + dx[i];
                    next.crush = true;
                    next.count = now.count + 1;
                    qSearch.push(next);
                    visit[next.y][next.x][next.crush]=true;
                }
                // 벽이 아니고 방문하지 않았으면
                else if (!visit[now.y + dy[i]][now.x + dx[i]][now.crush])
                {
                    bool check = false;
                    state next;
                    next.y = now.y + dy[i];
                    next.x = now.x + dx[i];
                    next.crush = now.crush;
                    next.count = now.count + 1;
                
                    qSearch.push(next);
                    visit[next.y][next.x][next.crush]=true;
                }
            }
        }
    }
    return;
}
int main(void)
{
    scanf("%d %d", &N, &M);
    nResult=N*M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            scanf("%1d", &map[i][j]);
            visit[i][j][0]=visit[i][j][1] = false;
        }
    DFS();
    if(flag)
        nResult=-1;
    printf("%d\n", nResult);
    return 0;
}
