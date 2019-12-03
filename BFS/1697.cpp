#include <iostream>
#include <utility>
#include <queue>

using namespace std;
const int tmax = 100001;
int N, K;
int check[100001];
void DFS(int point)
{
    queue<int> qSearch;
    qSearch.push(point);
    check[point] = 0;
    while (!qSearch.empty())
    {
        int visit = qSearch.front();
        qSearch.pop();
        if (visit - 1 >= 0)
            if (check[visit - 1] < 0)
            {
                qSearch.push(visit - 1);
                check[visit - 1] = check[visit] + 1;
                if (visit - 1 == K)
                    break;
            }
        if (visit + 1 < tmax)
            if (check[visit + 1] < 0)
            {
                qSearch.push(visit + 1);
                check[visit + 1] = check[visit] + 1;
                if (visit + 1 == K)
                    break;
            }
        if (visit * 2 < tmax)
            if (check[visit * 2] < 0)
            {
                qSearch.push(visit * 2);
                check[visit * 2] = check[visit] + 1;
                if (visit * 2 == K)
                    break;
            }
    }
}

int main(void)
{
    cin >> N >> K;
    for (int i = 0; i < 100001; i++)
        check[i] = -1;
    DFS(N);
    cout << check[K] << endl;
    return 0;
}