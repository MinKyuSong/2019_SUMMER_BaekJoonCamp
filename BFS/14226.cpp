// 정점 분리. 화면+클립보드 가 정점의 의미임.
// 화면, 클립보드 순서있게 push, pop 하면 일차원으로 처리 가능

#include <iostream>
#include <queue>

using namespace std;
typedef struct state
{
    int emoji;
    int clipboard;
} state;

int S;
int nResult;
int map[2000][2000];
bool check()
{
    for (int i = 0; i < 2000; i++)
        if (map[S][i] > 0)
        {
            nResult = map[S][i];
            return true;
        }
    return false;
}
void DFS(int point)
{
    queue<state> qSearch;
    state start;
    start.emoji = 1;
    start.clipboard = 0;
    map[start.emoji][start.clipboard] = 0;
    qSearch.push(start);
    while (!qSearch.empty())
    {
        state now(qSearch.front());
        qSearch.pop();

        // 복사
        if (now.emoji < 2000)
            if (map[now.emoji][now.emoji] < 0)
            {
                state temp(now);
                temp.clipboard = temp.emoji;
                map[temp.emoji][temp.clipboard] = map[now.emoji][now.clipboard] + 1;
                qSearch.push(temp);
                if(check())
                    break;
            }
        // 붙여넣기
        if (now.emoji + now.clipboard < 2000)
            if (map[now.emoji + now.clipboard][now.clipboard] < 0)
            {
                state temp(now);
                temp.emoji += temp.clipboard;
                map[temp.emoji][temp.clipboard] = map[now.emoji][now.clipboard] + 1;
                qSearch.push(temp);
                if(check())
                    break;
            }
        // 줄이기
        if (now.emoji - 1 >= 0)
            if (map[now.emoji - 1][now.clipboard] < 0)
            {
                state temp(now);
                temp.emoji--;
                map[temp.emoji][temp.clipboard] = map[now.emoji][now.clipboard] + 1;
                qSearch.push(temp);
                if(check())
                    break;
            }
    }
}

int main(void)
{
    cin >> S;
    for (int i = 0; i < 2000; i++)
        for (int j = 0; j < 2000; j++)
            map[i][j] = -1;
    DFS(1);
    cout << nResult << endl;
    return 0;
}