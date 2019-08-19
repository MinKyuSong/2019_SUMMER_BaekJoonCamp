#include <iostream>
using namespace std;

typedef struct pipe
{
    int y = 1;
    int x = 2;
} pipe;

static int map[18][18];
int N;
int nResult = 0;
// 가로, 대각, 세로
int dx[] = {1, 1, 0};
int dy[] = {0, 1, 1};
void go(int dir, pipe &p)
{
    pipe now(p);
    // check dir validation
    if (map[now.y + dy[dir]][now.x + dx[dir]] != 0)
        return;
    if(dir==1)
    {
        for(int i=0;i<3;i++)
            if (map[now.y + dy[i]][now.x + dx[i]] != 0)
                return;
    }
    if (now.y + dy[dir] > N || now.x + dx[dir] > N)
        return;
    else
    {
        // move
        now.y += dy[dir];
        now.x += dx[dir];
        if (now.y == N && now.x == N)
        {
            nResult++;
            return;
        }
        // search
        if (dir == 0)
        {
            for (int i = 0; i < 2; i++)
                go(i, now);
        }
        else if (dir == 1)
        {
            for (int i = 0; i < 3; i++)
                go(i, now);
        }
        else
        {
            for (int i = 1; i < 3; i++)
                go(i, now);
        }
    }
    return;
}

int main(void)
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];
    pipe p;
    for (int i = 0; i < 2; i++)
        go(i, p);

    cout << nResult << endl;
    return 0;
}