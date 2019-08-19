#include <iostream>

using namespace std;

// DP 로도 가능!
int N;
int nResult=-1;
static int nArrT[16];
static int nArrP[16];
static bool check[16];
void Freedom(int now)
{
    if(now>N)
    {
        int nTemp=0;
        for(int i=1;i<=N;i++)
            if(check[i])
                nTemp+=nArrP[i];
        if(nTemp>nResult)
            nResult=nTemp;
        return;
    }
    // 당일치기도 되니까
    if(now+nArrT[now]<=N+1)
    {
        check[now]=true;
        Freedom(now+nArrT[now]);
    }
    check[now]=false;
    Freedom(now+1);
}

int main(void)
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> nArrT[i] >> nArrP[i];
    }

    Freedom(1);

    cout<<nResult<<endl;
    return 0;
}

// bruteforce, semi-DP. day 부터 N일까지의 최대예상 수익을 반환하는 함수도 가능 
// 부분 최적을 모으면 전체 최적이 된다.
// 4일까지의 최대 + 4일 이후의 최대
// 퇴사2 도전!