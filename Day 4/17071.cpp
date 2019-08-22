#include <iostream>
#include<vector>
#include <queue>
#include <utility>
#define MAX 500000
using namespace std;

int N, K, T;
bool flag = true;
int nResult(MAX);
int dist[2][MAX + 1];
void BFS()
{
    queue<pair<int, int>> qSearch;
    dist[1][N]=0;
    qSearch.push(make_pair(N, 0));
    if (dist[0][N] == 0)
    {
        nResult = 0;
        flag = false;
        return;
    }
    while (!qSearch.empty())
    {
        int now(qSearch.front().first);
        int sec(qSearch.front().second);
        qSearch.pop();
        if (sec + 1 <= T && sec + 1 < nResult)
        {
            if (now - 1 >= 0)
            {
                int next = now - 1;
                if(dist[1][next]!=sec+1)
                {
                    if (dist[0][next] == sec+1)
                        if (nResult > sec+1)
                        {
                            flag = false;
                            nResult = sec+1;
                            return;
                        }
                    qSearch.push(make_pair(next, sec + 1));
                    dist[1][next]=sec+1;
                }
            }
            if (now + 1 <= MAX)
            {
                int next = now + 1;
                if(dist[1][next]!=sec+1)
                {
                    if (dist[0][next] == sec+1)
                        if (nResult > sec+1)
                        {
                            flag = false;
                            nResult = sec+1;
                            return;
                        }
                    qSearch.push(make_pair(next, sec + 1));
                    dist[1][next]=sec+1;
                }
            }
            if (now * 2 <= MAX)
            {
                int next = now * 2;
                if(dist[1][next]!=sec+1)
                {
                    if (dist[0][next] == sec+1)
                        if (nResult > sec+1)
                        {
                            flag = false;
                            nResult = sec+1;
                            return;
                        }
                    qSearch.push(make_pair(next, sec + 1));
                    dist[1][next]=sec+1;
                }
            }
        }
    }
}

int main(void)
{
    cin >> N >> K;

    for (int i = 0; i <= MAX; i++)
    {
        dist[1][i]=dist[0][i] = -1;
    }
    int temp = 0;
    for (int i = 0;; i++)
    {
        temp += i;
        if (K + temp > MAX)
        {
            T = i - 1;
            break;
        }
        dist[0][K + temp] = i;
    }
    BFS();
    if (flag)
        nResult = -1;
    cout << nResult << endl;

    return 0;
}