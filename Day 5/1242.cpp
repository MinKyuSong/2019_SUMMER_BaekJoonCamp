#include<iostream>
using namespace std;

int main(void)
{
    int ans=0;
    int N,K,M;
    cin>>N>>K>>M;

    int total=N, start=0, target=M-1;
    while(true)
    {
        ans++;
        if(total==0)
            break;
        int out=(start+K-1)%total;
        if(out==target)
            break;
        // 제거
        start=out;
        total--;
        if(target>=start)
            target--;
    }

    cout<<ans<<endl;
}