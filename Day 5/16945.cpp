#include<iostream>
#include<vector>
#include<algorithm>

#define maxn 1000;

using namespace std;
static int square[5][5];
int map[5][5];
int ans=maxn;

void calc(int target)
{
    int nResult=0;



    return;
}
int main(void)
{
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        {
            cin>>square[i][j];
            square[i][0]+=square[i][j];
            square[0][j]+=square[i][j];
            if(i==j)
                square[0][0]+=square[i][j];
            if(i==4-j)
                square[4][0]+=square[i][j];
        }
    for(int i=1;i<10;i++)
    {
        calc(i);
    }
    return 0;
}