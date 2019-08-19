// Not Finished
#include <cstdio>
using namespace std;
typedef struct coin
{
    int x, y;
};

int N, M;
int map[21][21];
coin coins[2];
int nResult=11;

int main(void)
{
    scanf("%d %d", &N, &M);
    int temp = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            char c;
            scanf("%c", &c);
            if (c == '.')
                map[i][j] = 0;
            else if (c == '#')
                map[i][j] = 1;
            else
            {
                coins[temp].y = i;
                coins[temp++].x = j;
            }
        }

    printf("%d\n",nResult);
    
    return 0;
}
