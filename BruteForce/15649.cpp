// endl은 시간이 오래 걸린다
// \n 쓰자
#include<iostream>
using namespace std;

static bool nArr[10];
int nChoice[10];
int N,M;

void MakeNum(int idx, int selected)
{
    if(idx>N+1)
        return;
    if(selected == M)
    {
        for(int i=0;i<M;i++)
            cout<<nChoice[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<=N;i++)
    {
        if(nArr[i])
            continue;
        nArr[i]=true;
        nChoice[idx]=i;
        MakeNum(idx+1,selected+1);
        nArr[i]=false;
    }
    return;
}

int main(void)
{
    cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
    cin>>N>>M;
    
    MakeNum(0,0);

    return 0;
}