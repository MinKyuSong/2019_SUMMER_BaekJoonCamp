#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int mapOriginal[10][10];
int mapCopy[10][10];
bool visit[10][10];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

int N, M;
int nResult = 0;

bool valid(int y, int x)
{
    return (y >= 0 && y < N && x >= 0 && x < M);
}

void clone()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            mapCopy[i][j] = mapOriginal[i][j];
}

void spread()
{
    queue<pair<int, int>> qSearch;
    int nCount = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            visit[i][j]=false;
            if (mapCopy[i][j] == 2)
                {
                    qSearch.push(make_pair(i, j));
                    nCount++;
                }
            if(mapCopy[i][j] == 1)
                nCount++;
        }
    while (!qSearch.empty())
    {
        int y, x;
        y = qSearch.front().first;
        x = qSearch.front().second;
        qSearch.pop();

        for (int i = 0; i < 4; i++)
        {
            if (valid(y + dy[i], x + dx[i]))
                if (mapCopy[y + dy[i]][x + dx[i]] == 0 && !visit[y + dy[i]][x + dx[i]])
                {
                    visit[y + dy[i]][x + dx[i]]=true;
                    nCount++;
                    qSearch.push(make_pair(y + dy[i], x + dx[i]));
                }
        }
    }

    if (N*M - nCount > nResult)
        nResult = N*M - nCount;
    return;
}

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
                cin >> mapOriginal[i][j];

    clone();
    for (int i = 0; i < N * M - 2; i++)
    {
        int ty, tx;
        ty=i/M; tx=i%M;
        if (mapOriginal[ty][tx] == 0)
        {
            mapCopy[ty][tx] = 1;
            for (int j = i + 1; j < N * M - 1; j++)
            {
                int ty, tx;
                ty=j/M;tx=j%M;
                if (mapOriginal[ty][tx] == 0)
                {
                    mapCopy[ty][tx] = 1;
                    for (int k = j + 1; k < N * M; k++)
                    {
                        int ty, tx;
                        ty=k/M;tx=k%M;
                        if (mapOriginal[ty][tx] == 0)
                        {
                            mapCopy[ty][tx] = 1;
                            spread();
                            mapCopy[ty][tx] = 0;
                        }
                    }
                    mapCopy[ty][tx] = 0;
                }
            }
            mapCopy[ty][tx] = 0;
        }
    }
    cout << nResult << endl;
    return 0;
}